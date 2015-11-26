word_samples  = data_set.windowed_feature_vectors(word_features, window_size=word_window_size)
classes       = data_set.windowed_tag_sequences(window_size=1)
unvec_classes = to_vector(unvectorize(classes))
previous_tag_samples = np.ones((len(word_samples), tag_window_size))

for e in range(nb_epoch):

    previous_tag_samples[:,:] = data_set.tokenizer.unknown_tag_index
    j = 0

    for i, sentence in enumerate(data_set.word_id_sentences):

        k = j+len(sentence)
        word_window = word_samples[j:k]
        tag_window = previous_tag_samples[j:k]
        classes_window = classes[j:k]
        indexes_predicted = [-1 for _ in range(len(sentence))]
        count = 0

        while count < len(sentence):
            samples = [word_window, tag_window]
            model.train_on_batch(samples, classes_window)
            predicts = model.predict_on_batch(samples)
            bigger_id, bigger_value, bigger_index = get_bigger_not_yet_predicted(predicts, indexes_predicted)
            update_k_window_with_value(tag_window, bigger_index, bigger_id)
            count += 1

        j += len(sentence)
