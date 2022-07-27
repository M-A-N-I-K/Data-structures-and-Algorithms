/*
Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :

No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :

The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :

While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :

For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :

1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :

1
10 9 8 7 6 5 4 3 -1

Sample Output 1 :

 3 4 5 6 7 8 9 10

 Sample Output 2 :

2
-1
10 -5 9 90 5 67 1 89 -1

Sample Output 2 :

-5 1 5 9 10 67 89 90

*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
    {
        return NULL;
    }
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *newHead = NULL;
    Node *newTail = NULL;
    if (head1->data > head2->data)
    {
        newHead = head2;
        newTail = head2;
        head2 = head2->next;
    }
    else
    {
        newHead = head1;
        newTail = head1;
        head1 = head1->next;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data > head2->data)
        {
            newTail->next = head2;
            head2 = head2->next;
            newTail = newTail->next;
        }
        else
        {
            newTail->next = head1;
            head1 = head1->next;
            newTail = newTail->next;
        }
    }
    if (head1 == NULL)
    {
        newTail->next = head2;
    }
    else
    {
        newTail->next = head1;
    }
    return newHead;
}
Node *midPoint(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *firstHalf = head;
    Node *mid = midPoint(head);
    Node *secondHalf = mid->next;
    mid->next = NULL;
    firstHalf = mergeSort(head);
    secondHalf = mergeSort(secondHalf);
    Node *newHead = mergeTwoSortedLinkedLists(firstHalf, secondHalf);
    return newHead;
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        head = mergeSort(head);
        print(head);
    }

    return 0;
}