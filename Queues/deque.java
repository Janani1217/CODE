/*
 * Dequeue ::
 * 
 * Hybrid adaptation of stack and a queue
 * Gives a liberty of inserting and deleting at the front and the back.
 * 
 * Functions :
 * 1. push_back()
 * 2. push_front()
 * 3. pop_front()
 * 4. pop_back()
 * 5. front()
 * 6. back()
 * 7. size()
 * 8. empty()
 * 
 * .............................................................................
 * 
 * What are the functions to be called in a deque to impl a stack ?
 * 
 * 1. push_back() - insert
 * 2. pop_back() - pop
 * 3. size()
 * 4. empty()
 * 5. back() - peek
 * 
 * 
 * .............................................................................
 * 
 * What are the functions to be called in a deque to impl a queue ?
 * 
 * 1. push_back() - insert
 * 2. pop_front() - pop
 * 3. size()
 * 4. empty()
 * 5. front() - peek
 * 
 * .............................................................................
 * 
 * Treating Dequeue as a SLIDING WINDOW ::
 * 
 * 1. a dequeue can grow from both the sides
 * 2. treating it as a sliding window
 * 3. add to the window by -> push_back()
 * 4. remove from the window by -> pop_front()
 * 
 * Dynamically growing !!
 * 
 */