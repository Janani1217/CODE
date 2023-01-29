#include <iostream>
using namespace std;

/*
insert node
reverse in k groups
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
int getLengthOfList(Node *head, int n)
{
    if (head == NULL)
        return n;
    return getLengthOfList(head->next, n + 1);
}

Node *getKReverse(Node *head, int k)
{
    // base case
    if (head == NULL)
        return NULL;

    // first check whether k nodes exists or not
    Node *curr = head;
    Node *temp = curr;
    int countOfExistingNodes = 0;
    while (temp != NULL && countOfExistingNodes < k)
    {
        temp = temp->next;
        countOfExistingNodes++;
    }
    if (countOfExistingNodes != k)
    {
        return head;
    }

    // now reverse first group of k nodes
    Node *prev = NULL;
    Node *forward = NULL;
    int count = 0; // to count till k nodes

    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // check forward is null or not to attach the first reveresed group
    if (forward != NULL)
        head->next = getKReverse(forward, k); // head will be pointing to first node in the actual ll

    return prev;
}

int main()
{
    Node *node = new Node(2);
    Node *head = node;
    insertAtTail(head, 4);
    insertAtTail(head, 6);
    insertAtTail(head, 3);
    insertAtTail(head, 1);
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    insertAtTail(head, 9);

    int n = getLengthOfList(head, 1);
    Node *result = getKReverse(head, 4);
    printList(result);
    cout << "\n";
    return 0;
}
