/*
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :

The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :

Each level linked list is printed in new line (elements are separated by space).

Constraints:

Time Limit: 1 second

Sample Input 1:

5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:

5
6 10
2 3
9

*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        vector<Node<int> *> vec;
        vec.push_back(NULL);
        return vec;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    vector<Node<int> *> vec;
    while (pendingNodes.size() != 0)
    {

        BinaryTreeNode<int> *curr = pendingNodes.front();
        pendingNodes.pop();
        if (curr == NULL)
        {
            tail->next = NULL;
            Node<int> *temp = head;
            vec.push_back(head);
            if (pendingNodes.size() == 0)
            {
                break;
            }
            pendingNodes.push(NULL);
            head = NULL;
            tail = NULL;
        }
        else
        {
            if (curr != NULL)
            {
                Node<int> *newNode = new Node<int>(curr->data);
                if (head == NULL)
                {
                    head = newNode;
                    tail = newNode;
                }
                else
                {
                    tail->next = newNode;
                    tail = tail->next;
                }
            }
            if (curr->left != NULL)
            {
                pendingNodes.push(curr->left);
            }
            if (curr->right != NULL)
            {
                pendingNodes.push(curr->right);
            }
        }
    }
    return vec;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++)
    {
        print(ans[i]);
    }
}