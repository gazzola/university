word_model = Sequential()
word_model.add(Embedding(input_dim, embeddings_size, weights=[embeddings_weights], 
						input_length=window_size))

capitalization_model = Sequential()
capitalization_model.add(Embedding(capitalizations_vocab_dim, capitalization_length, 
			weights=[capitalization_weights], input_length=window_size))

prefix_model = Sequential()
prefix_model.add(Embedding(prefix_vocab_dim, prefix_size, weights=[prefixes_weights], 
							input_length=window_size*prefixes_length))
prefix_model.add(Reshape((window_size, prefixes_length*prefix_size)))

suffix_model = Sequential()
suffix_model.add(Embedding(suffix_vocab_dim, suffix_size, weights=[suffixes_weights], 
							input_length=window_size*suffixes_length))
suffix_model.add(Reshape((window_size, suffixes_length*suffix_size)))

model = Sequential()
model.add(Merge([word_model, capitalization_model, prefix_model, suffix_model], mode='concat'))
model.add(Flatten())
model.add(Dense(hidden_dim, activation='relu'))
model.add(Dropout(keep_dropout))
model.add(Dense(output_dim, activation='softmax'))

model.compile(loss='categorical_crossentropy', optimizer='adadelta', class_mode="categorical")