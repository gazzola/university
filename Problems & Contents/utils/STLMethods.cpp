DEQUE
-----

Member functions
* (constructor) -> Construct deque container (public member function )
* (destructor) -> Deque destructor (public member function )
* operator= -> Assign content (public member function )


Iterators:
* begin -> Return iterator to beginning (public member function )
* end -> Return iterator to end (public member function )
* rbegin -> Return reverse iterator to reverse beginning (public member function )
* rend -> Return reverse iterator to reverse end (public member function )


Capacity:
* size -> Return size (public member function )
* max_size -> Return maximum size (public member function )
* resize -> Change size (public member function )
* empty -> Test whether container is empty (public member function )


Element access:
* operator[] -> Access element (public member function )
* at -> Access element (public member function )
* front -> Access first element (public member function )
* back -> Access last element (public member function )


Modifiers:
* assign -> Assign container content (public member function )
* push_back -> Add element at the end (public member function )
* push_front -> Insert element at beginning (public member function )
* pop_back -> Delete last element (public member function )
* pop_front -> Delete first element (public member function )
* insert -> Insert elements (public member function )
* erase -> Erase elements (public member function )
* swap -> Swap content (public member function )
* clear -> Clear content (public member function )
* emplace -> Construct and insert element (public member function )


Allocator:
* get_allocator -> Get allocator (public member function )


Non-member functions overloads
* relational operators -> Relational operators for deque (function )
* swap -> Exchanges the contents of two deque containers (function template )




PRIORITY_QUEUE
--------------

Member functions
* (constructor) ->Construct priority queue (public member function )
* empty -> Test whether container is empty (public member function )
* size -> Return size (public member function )
* top -> Access top element (public member function )
* push -> Insert element (public member function )
* pop -> Remove top element (public member function )



MAP
---

Member functions
* (constructor) -> Construct map (public member function )
* (destructor) -> Map destructor (public member function )
* operator= -> Copy container content (public member function )


Iterators:
* begin -> Return iterator to beginning (public member function )
* end -> Return iterator to end (public member function )
* rbegin -> Return reverse iterator to reverse beginning (public member function )
* rend -> Return reverse iterator to reverse end (public member function )
* cbegin -> Return const_iterator to beginning (public member function )
* cend -> Return const_iterator to end (public member function )
* crbegin -> Return const_reverse_iterator to reverse beginning (public member function )
* crend -> Return const_reverse_iterator to reverse end (public member function )


Capacity:
* empty -> Test whether container is empty (public member function )
* size -> Return container size (public member function )
* max_size -> Return maximum size (public member function )


Element access:
* operator[] -> Access element (public member function )


Modifiers:
* insert -> Insert elements (public member function )
* erase -> Erase elements (public member function )
* swap -> Swap content (public member function )
* clear -> Clear content (public member function )


Observers:
* key_comp -> Return key comparison object (public member function )
* value_comp -> Return value comparison object (public member function )


Operations:
* find -> Get iterator to element (public member function )
* count -> Count elements with a specific key (public member function )
* lower_bound -> Return iterator to lower bound (public member function )
* upper_bound -> Return iterator to upper bound (public member function )
* equal_range -> Get range of equal elements (public member function )


Allocator:
* get_allocator -> Get allocator (public member function )




SET
---

Member functions
* (constructor) -> Construct set (public member function )
* (destructor) -> Set destructor (public member function )
* operator= -> Copy container content (public member function )


Iterators:
* begin -> Return iterator to beginning (public member function )
* end -> Return iterator to end (public member function )
* rbegin -> Return reverse iterator to reverse beginning (public member function )
* rend -> Return reverse iterator to reverse end (public member function )


Capacity:
* empty -> Test whether container is empty (public member function )
* size -> Return container size (public member function )
* max_size -> Return maximum size (public member function )


Modifiers:
* insert -> Insert element (public member function )
* erase -> Erase elements (public member function )
* swap -> Swap content (public member function )
* clear -> Clear content (public member function )


Observers:
* key_comp -> Return comparison object (public member function )
* value_comp -> Return comparison object (public member function )


Operations:
* find -> Get iterator to element (public member function )
* count -> Count elements with a specific value (public member function )
* lower_bound -> Return iterator to lower bound (public member function )
* upper_bound -> Return iterator to upper bound (public member function )
* equal_range -> Get range of equal elements (public member function )


Allocator:
* get_allocator -> Get allocator (public member function )




STACK
-----

* (constructor) ->Construct stack (public member function )
* empty -> Test whether container is empty (public member function )
* size -> Return size (public member function )
* top -> Access next element (public member function )
* push -> Insert element (public member function )
* emplace -> Construct and insert element (public member function )
* pop -> Remove top element (public member function )




VECTOR
------


Member functions
* (constructor) -> Construct vector (public member function )
* (destructor) -> Vector destructor (public member function )
* operator= -> Assign content (public member function )


Iterators:
* begin -> Return iterator to beginning (public member function )
* end -> Return iterator to end (public member function )
* rbegin -> Return reverse iterator to reverse beginning (public member function )
* rend -> Return reverse iterator to reverse end (public member function )


Capacity:
* size -> Return size (public member function )
* max_size -> Return maximum size (public member function )
* resize -> Change size (public member function )
* capacity -> Return size of allocated storage capacity (public member function )
* empty -> Test whether vector is empty (public member function )
* reserve -> Request a change in capacity (public member function )


Element access:
* operator[] -> Access element (public member function )
* at -> Access element (public member function )
* front -> Access first element (public member function )
* back -> Access last element (public member function )


Modifiers:
* assign -> Assign vector content (public member function )
* push_back -> Add element at the end (public member function )
* pop_back -> Delete last element (public member function )
* insert -> Insert elements (public member function )
* erase -> Erase elements (public member function )
* swap -> Swap content (public member function )
* clear -> Clear content (public member function )


Allocator:
* get_allocator -> Get allocator (public member function )


Non-member function overloads
* relational operators -> Relational operators for vector (function template )
* swap -> Exchange contents of vectors (function template )


Template specializations
* vector<bool> -> Vector of bool (class template specialization )