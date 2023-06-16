/*
Reorder List :
Given a singly linked list: A0→A1→...→An-2→An-1, reorder it to: A0→An-1→A1→An-2→A2→An-3→...
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

https://practice.geeksforgeeks.org/problems/reorder-list/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

Refer the video for solution : https://www.youtube.com/watch?v=meOY1wajrnw

TC : O(n)
SC : O(1)
*/

// TC : O(n) , SC : O(n) approach
void solve(Node *head)
{
    // use of stack to store the ele
    // first traverse the list :

    Node *temp = head;
    stack<Node *> st;
    int size = 0;

    while (!temp)
    {
        st.push(temp);
        temp = temp->next;
        size++;
    }

    // need to re arrange only 1/s of list
    int count = size / 2;

    // so pop only till count on the stack
    temp = head;
    while (count--)
    {
        Node *nxt = temp->next;
        temp->next = st.top();
        st.pop();
        temp = temp->next;
        temp->next = nxt;
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}

/*
But this approach can be space optimized , by reversing half of the list since
only last half of the list has to be modified.

So first reverse the last half using slow and fast ptrs
Then traverse the list using 2 pointers and doing the reordering
*/

// TC : O(n) , SC : O(1)

void solve(Node *head)
{
    if (!head || !head->next)
        return;

    // first reverse the last half of list
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // half list is pointed by slow pointer
    // reverse the list present after the slow ptr

    Node *prev = NULL;
    Node *curr = slow;
    Node *nxt;

    while (curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // make 2 pointers to both the list , though present in single list only
    Node *n1 = head;
    Node *n2 = prev;

    // ***** IMP CONDITION ***** //
    while (n2->next)
    {
        temp = n1->next;
        n1->next = n2;
        n1 = temp;

        temp = n2->next;
        n2->next = n1;
        n2 = temp;
    }
}
