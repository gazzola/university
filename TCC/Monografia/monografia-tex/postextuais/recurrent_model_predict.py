window = data_set.windowed_word_sequences(window_size=window_size)
capitalizations, prefixes, suffixes = get_manual_features(window, data_set.tokenizer.indexes_to_words)
data = {'word_input':window, 'capitalization_input':capitalizations, 
	'prefix_input':prefixes, 'suffix_input':suffixes}
predicted_classes = np.argmax(model.predict(data, batch_size=batch_size, verbose=1)['output'], axis=-1)
return predicted_classes