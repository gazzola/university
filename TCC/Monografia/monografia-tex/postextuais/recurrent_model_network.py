model = Graph()

# WORD MODEL
model.add_input(name='word_input', input_shape=(window_size, ), dtype=int)
model.add_node(Embedding(input_dim, embeddings_size, 
        weights=[embeddings_weights], 
        input_length=window_size), 
        name='word_embedding', 
        input='word_input')

# CAPITALIZATION MODEL
model.add_input(name='capitalization_input', input_shape=(window_size, ), dtype=int)
model.add_node(Embedding(capitalizations_vocab_dim, capitalization_length, 
        weights=[capitalization_weights], 
        input_length=window_size), 
        name='capitalization_embedding', 
        input='capitalization_input')

# PREFIX MODEL
model.add_input(name='prefix_input', input_shape=(window_size, ), dtype=int)
model.add_node(Embedding(prefix_vocab_dim, prefix_size, 
        weights=[prefixes_weights], 
        input_length=window_size*prefixes_length), 
        name='prefix_embedding_concatened', input='prefix_input')
model.add_node(Reshape((window_size, prefixes_length*prefix_size)), 
        name='prefix_embedding', 
        input='prefix_embedding_concatened')

# SUFFIX MODEL
model.add_input(name='suffix_input', input_shape=(window_size, ), dtype=int)
model.add_node(Embedding(suffix_vocab_dim, suffix_size, 
        weights=[suffixes_weights], 
        input_length=window_size*suffixes_length), 
        name='suffix_embedding_concatened', 
        input='suffix_input')
model.add_node(Reshape((window_size, suffixes_length*suffix_size)), 
        name='suffix_embedding', 
        input='suffix_embedding_concatened')

# FINAL MODEL
model.add_node(GRU(hidden_dim, return_sequences=True, activation='relu'),                    
        name='forward', 
        inputs=['word_embedding', 'capitalization_embedding', 'suffix_embedding', 'prefix_embedding'], 
        merge_mode='concat')
model.add_node(GRU(hidden_dim, return_sequences=True, activation='relu', go_backwards=True), 
        name='backward', 
        inputs=['word_embedding', 'capitalization_embedding', 'suffix_embedding', 'prefix_embedding'], 
        merge_mode='concat')
model.add_node(Dropout(keep_dropout), name='dropout', inputs=['forward', 'backward'], merge_mode='sum')
model.add_node(Flatten(), name='flatten', input='dropout')
model.add_node(Dense(output_dim, activation='softmax'), name='softmax', input='flatten')
model.add_output(name='output', input='softmax')

model.compile('adadelta', {'output': 'categorical_crossentropy'})