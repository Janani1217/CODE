/*
Queue :
Insertion and deletion happens in diff ends , which is indicated by rear and front.
Queue follows : first in first out
Queue is impl using 2 stacks = s1, s2

Make the enqueue operation costly:
1.  so in queue if a ele is inserted it should be on the top of the stack to
    be retrieved.

2.  Hence when a new item is inserted is pushed in s1 -> always on the top
    So the dequeu operation will just pop the top of s1

3.  To put the ele at the top of s1 , s2 is used.

Algorithm :

1.  while s1 is not empty -> push everything from s1 to s2
2.  push new ele = x -> s1
3.  push everything back into stack

DeQueue (q) :
1. if s1 -> empty : return err
2. s1.top(), s1.pop()
*/