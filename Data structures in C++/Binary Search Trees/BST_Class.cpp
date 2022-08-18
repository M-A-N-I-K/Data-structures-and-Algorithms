/*
Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BST or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -

N:L:x,R:y

where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
*/
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

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

class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

private:
    bool hasDataHelper(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        else if (root->data > data)
        {
            return hasDataHelper(data, root->left);
        }
        else if (root->data < data)
        {
            return hasDataHelper(data, root->right);
        }
    }

    BinaryTreeNode<int> *insertHelper(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
            return root;
        }
        else if (data <= root->data)
        {
            BinaryTreeNode<int> *leftTree = insertHelper(data, root->left);
            root->left = leftTree;
            return root;
        }
        else
        {
            BinaryTreeNode<int> *rightTree = insertHelper(data, root->right);
            root->right = rightTree;
            return root;
        }
    }

    int minimum(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return INT_MAX;
        }
        return min(root->data, min(minimum(root->left), minimum(root->right)));
    }

    BinaryTreeNode<int> *deleteDataHelper(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data > data)
        {
            BinaryTreeNode<int> *ans = deleteDataHelper(data, root->left);
            return ans;
        }
        else if (root->data < data)
        {
            BinaryTreeNode<int> *ans = deleteDataHelper(data, root->right);
            return ans;
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL)
            {
                return root->right;
            }
            else if (root->right == NULL)
            {
                return root->left;
            }
            else
            {
                int minData = minimum(root->right);
                root->data = minData;
                BinaryTreeNode<int> *ans = deleteDataHelper(minData, root->right);
                root->right = ans;
                return root;
            }
        }
    }

    void printTreeHelper(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right != NULL)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        printTreeHelper(root->left);
        printTreeHelper(root->right);
    }

public:
    bool search(int data)
    {
        return hasDataHelper(data, root);
    }

    void insert(int data)
    {
        root = insertHelper(data, root);
    }

    void remove(int data)
    {
        root = deleteDataHelper(data, root);
    }

    void print()
    {
        printTreeHelper(root);
    }
};

int main()
{
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->remove(input);
            break;
        case 3:
            cin >> input;
            cout << ((tree->search(input)) ? "true\n" : "false\n");
            break;
        default:
            tree->print();
            break;
        }
    }
}