window = data_set.windowed_word_sequences(window_size=window_size)
classes = data_set.windowed_tag_sequences(window_size=1)
capitalizations, prefixes, suffixes = get_manual_features(window, data_set.tokenizer.indexes_to_words)

val_window = validation_data_set.windowed_word_sequences(window_size=window_size)
val_classes = validation_data_set.windowed_tag_sequences(window_size=1)
val_capitalizations, val_prefixes, val_suffixes = get_manual_features(val_window, 
						data_set.tokenizer.indexes_to_words)


callbacks.append(ModelCheckpoint(filepath=weights_file, verbose=1, save_best_only=True))
callbacks.append(TagAccuracy(validation_data, eval_func=calculate_accuracy))

train_data = {'word_input':window, 'capitalization_input':capitalizations, 
		'prefix_input':prefixes, 'suffix_input':suffixes, 'output':classes}

validation_data = {'word_input':val_window, 'capitalization_input':val_capitalizations, 
		'prefix_input':val_prefixes, 'suffix_input':val_suffixes, 'output':val_classes}

model.fit(train_data, nb_epoch=nb_epoch, batch_size=batch_size, validation_split=validation_split, 
	validation_data=validation_data, callbacks=callbacks)