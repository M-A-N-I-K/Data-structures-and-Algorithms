/*
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :

The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format:

The first and only line of output contains the height of the largest BST.

Constraints:

Time Limit: 1 second

Sample Input 1:

5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:

2

*/
#include <iostream>
#include <queue>
#include <climits>

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
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

class largestBST
{
public:
    int min;
    int max;
    bool isBST;
    int maxHeight;
};

using namespace std;

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

largestBST largestBSTSubTreeHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        largestBST ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBST = true;
        ans.maxHeight = 0;
        return ans;
    }
    if (root->left == NULL && root->right == NULL)
    {
        largestBST ans;
        ans.min = root->data;
        ans.max = root->data;
        ans.isBST = true;
        ans.maxHeight = 1;
        return ans;
    }
    largestBST leftAns = largestBSTSubTreeHelper(root->left);
    largestBST rightAns = largestBSTSubTreeHelper(root->right);
    largestBST ans;
    ans.min = min(leftAns.min, min(rightAns.min, root->data));
    ans.max = max(rightAns.max, max(leftAns.max, root->data));
    ans.isBST = (root->data > leftAns.max) && (root->data < rightAns.min) && leftAns.isBST && rightAns.isBST;
    if (ans.isBST == false)
    {
        ans.maxHeight = max(leftAns.maxHeight, rightAns.maxHeight);
        return ans;
    }
    ans.maxHeight = max(leftAns.maxHeight, rightAns.maxHeight) + 1;
    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    largestBST ans = largestBSTSubTreeHelper(root);
    return ans.maxHeight;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}