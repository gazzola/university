word_samples  = data_set.windowed_feature_vectors(word_features, window_size=word_window_size)
classes       = data_set.windowed_tag_sequences(window_size=1)
unvec_classes = to_vector(unvectorize(classes))
previous_tag_samples = np.ones((len(word_samples), beam_size, tag_window_size))
previous_tag_samples = previous_tag_samples * data_set.tokenizer.unknown_tag_index
predictions     = np.ones(unvec_classes.shape) * data_set.tokenizer.unknown_tag_index
j = 0

for i, sentence in enumerate(data_set.word_id_sentences):

    k = j+len(sentence)
    word_window = word_samples[j:k]
    tag_window = previous_tag_samples[j:k]
    classes_window = classes[j:k]
    beam_probs, beam_sequences, beam_predicts = [], [], []

    for b in range(beam_size):
        beam_probs.append(1)
        beam_sequences.append([-1 for _ in range(len(sentence))])
        samples = [word_window, tag_window[:, b]]
        beam_predicts.append(model.predict_on_batch(samples))

    b = 0 # all beam_predicts are equal at this time
    word_index = beam_predicts[b].max(axis=-1).argmax()
    bigger_window_index = word_index + j

    pq = PriorityQueue() # heap
    for tag, prob_tag in enumerate(beam_predicts[b][word_index]):
        item = (bigger_window_index, tag, b, 1, [])
        prior = prob_tag
        pq.push_and_trunc(item, prior, beam_size)

    for count in range(len(sentence)):

        pq.remake_beans()
        bigger_items = pq.get_items()
        prox_index, prox_value = 0, 0

        for bigger_window_index, bigger_id, b, _, _ in bigger_items:
            word_index = bigger_window_index-j
            bigger_value = beam_predicts[b][word_index, bigger_id]

            # tag_window for b
            for bi, wi in enumerate(beam_sequences[b]):
                if wi != -1:
                    for l in range(tag_window_size):
                        t = bi + l - tag_window_size // 2
                        if t >= 0 and t < tag_window.shape[0]:
                            tag_window[t, b, l] = bigger_id

            samples = [word_window, tag_window[:, b]]
            beam_probs[b] *= bigger_value
            beam_sequences[b][word_index] = bigger_id
            beam_predicts[b] = model.predict_on_batch(samples)

            for iw, prob_bigger_word in enumerate(beam_predicts[b].max(axis=-1)):
                if not_in_list_index(beam_sequences[b], iw) and prob_bigger_word > prox_value:
                    prox_value = prob_bigger_word
                    prox_index = iw

        bigger_window_index = prox_index + j
        for b in range(beam_size):
            for it, prob_tag in enumerate(beam_predicts[b][prox_index, :]):
                prior = prob_tag * beam_probs[b]
                item = (bigger_window_index, it, b, beam_probs[b], beam_sequences[b])
                pq.push_and_trunc(item, prior, beam_size)

        items = pq.get_items_and_back() # get items in reverse order and put them back in heap
        for b, (bigger_window_index, bigger_id, b_pred, b_prior, b_seq) in enumerate(items):
            beam_sequences[b] = b_seq[:] # make a copy
            beam_probs[b] = float(b_prior)

    max_predict_index = np.argmax(np.sum(np.array(beam_sequences) == unvec_classes, axis=-1))
    for p in range(j, k):
        predictions[p] = beam_sequences[max_predict_index][p-j]

    j += len(sentence)

return predictions