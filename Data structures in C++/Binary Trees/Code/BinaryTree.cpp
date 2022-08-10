#include <iostream>
using namespace std;

template <typename T>
class binaryTreeNode
{
public:
    T data;
    binaryTreeNode *left;
    binaryTreeNode *right;

    binaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};

void printTree(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

binaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data :" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    binaryTreeNode<int> *leftChild = takeInput();
    binaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int main()
{
    /*
    binaryTreeNode<int> *root = new binaryTreeNode<int>(1);
    binaryTreeNode<int> *node1 = new binaryTreeNode<int>(2);
    binaryTreeNode<int> *node2 = new binaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    */
    binaryTreeNode<int> *root = takeInput();
    printTree(root);
    delete root;
    return 0;
}