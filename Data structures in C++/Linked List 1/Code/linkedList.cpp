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
        next = NULL;
    }
};

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
    // Statically
    Node first(10);
    Node *head = &first;
    Node second(20);
    first.next = &second;

    // cout << first.data << " " << second.data << endl;
    print(head);
    return 0;
}