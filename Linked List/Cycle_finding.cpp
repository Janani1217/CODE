/*
Find the point where the cycle exists in the linked list.

Approach : Floyd's Cycle finding algorithm

1.  Also called Hare-Tortoise algo
2.  using fast and slow ptrs
3.  move slow 1 step and fast 2 steps in while loop
4.  if they meet -> indicates cycle exists
5.  now here , initiate slow = head
6.  move both 1 step till both meets
7.  they both will only meet at the cycle point
8.  else return NULL

*/

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                // cycle found
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};