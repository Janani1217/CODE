#include <iostream>
using namespace std;

/*
insert node
print kth last node
with single recr too
get reverse of ll
*/

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtTail(Node *&head, int data)
{
    Node *node = new Node(data);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    return;
}

void printList(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data;
    printList(head->next);
}

void printKLastUtils(Node *head, int rem)
{
    if (head == NULL)
        return;
    if (rem == 0)
    {
        cout << head->data;
        return;
    }
    printKLastUtils(head->next, rem - 1);
}

void printKLast(Node *head, int k)
{
    int n = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    k = n - k;
    printKLastUtils(head, k - 1);
}

void printKLastSingleRecr(Node *head, int &k, int n)
{
    if (head == NULL || k > n)
    {
        return;
    }

    printKLastSingleRecr(head->next, k, n);

    if (k == 1)
        cout << head->data << "\n";
    k = k - 1;
}

int getLengthOfList(Node *head, int n)
{
    if (head == NULL)
        return n;
    return getLengthOfList(head->next, n + 1);
}

/*first we should think that the recr function will reversse
the given list from the second index automatically and the output
will be : 3 1 6 4 .
Now we have to just take care of the 1st node = 3, here this has
to be after 4 in the output.
So anyhow 4 is pointed by head (head->next = 4).
So now head->next->next = 5(head now).
Now currRes is pointed to 3 here, which will be returned back
*/

Node *getReverse(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *currRes = getReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return currRes;
}

// iterative reversal of linked list approach :
Node *reverse(Node *head)
{
    if (head == NULL)
        return head;

    Node *prev = NULL;
    Node *curr = head;
    Node *nx = NULL;

    while (curr != NULL)
    {
        nx = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nx;
    }
    return prev;
}

int main()
{
    Node *node = new Node(2);
    Node *head = node;
    insertAtTail(head, 4);
    insertAtTail(head, 6);
    insertAtTail(head, 1);
    insertAtTail(head, 3);

    // printKLast(head,3);

    int n = getLengthOfList(head, 1);

    // int k = 5;
    // printKLastSingleRecr(head, k, n);

    // addition of 2 linked list
    Node *node2 = new Node(4);
    Node *head2 = node2;
    insertAtTail(head2, 5);
    insertAtTail(head2, 1);

    // reverse of both ll
    Node *ans1 = getReverse(head);
    // printList(ans1);
    // cout << "\n";
    Node *ans2 = getReverse(head2);
    // printList(ans2);

    head = ans1;
    head2 = ans2;
    int sum = head->data + head2->data;
    int carry = 0;
    if (sum > 9)
    {
        sum = sum % 10;
        carry = 1;
    }
    else
    {
        carry = 0;
    }
    Node *result = new Node(sum);
    head = head->next;
    head2 = head2->next;

    while (head != NULL && head2 != NULL)
    {
        sum = carry + head->data + head2->data;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        insertAtTail(result, sum);
        head = head->next;
        head2 = head2->next;
    }

    while (head != NULL)
    {
        if (carry == 1)
        {
            insertAtTail(result, carry + (head->data));
            carry = 0;
        }
        else
        {
            insertAtTail(result, head->data);
        }
        head = head->next;
    }
    while (head2 != NULL)
    {
        if (carry == 1)
        {
            insertAtTail(result, carry + (head2->data));
            carry = 0;
        }
        else
        {
            insertAtTail(result, head2->data);
        }
        head2 = head2->next;
    }
    result = getReverse(result);
    printList(result);
    cout << "\n";
    return 0;
}
