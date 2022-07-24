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

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

Node *insertNode(Node *head, int pos, int data)
{
    Node *p = new Node(data);
    if (pos == 0)
    {
        p->next = head;
        head = p;
        return head;
    }
    Node *temp = head;
    int i = 0;
    while (temp != NULL && i != pos - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp != NULL)
    {

        p->next = temp->next;
        temp->next = p;
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
    // Statically
    // Node first(10);
    // Node *head = &first;
    // Node second(20);
    // first.next = &second;
    /*
    // Dynamically
    Node *n1 = new Node(10);
    Node *head = n1;
    Node *n2 = new Node(20);
    n1->next = n2;
    */

    // cout << first.data << " " << second.data << endl;
    // print(head);

    Node *head = takeInput();
    int pos, data;
    cin >> pos >> data;
    head = insertNode(head, pos, data);
    print(head);
    return 0;
}