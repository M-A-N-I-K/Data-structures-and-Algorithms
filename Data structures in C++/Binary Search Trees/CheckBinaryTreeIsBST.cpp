/*
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
Input format :

The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :

The first and only line of output contains either true or false.

Constraints :

Time Limit: 1 second

Sample Input 1 :

3 1 5 -1 2 -1 -1 -1 -1

Sample Output 1 :

true

Sample Input 2 :

5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1

Sample Output 2 :

false

*/
#include <iostream>
#include <queue>
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
/*
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    return (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
}
*/
pair<pair<int, int>, bool> isBSTHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<pair<int, int>, bool> p;
        p.first.first = INT_MAX;
        p.first.second = INT_MIN;
        p.second = true;
        return p;
    }
    pair<pair<int, int>, bool> leftMax = isBSTHelper(root->left);
    pair<pair<int, int>, bool> rightMin = isBSTHelper(root->right);
    int minimum = min(root->data, min(leftMax.first.first, rightMin.first.first));
    int maximum = max(root->data, max(leftMax.first.second, rightMin.first.second));
    bool isBSTAns = leftMax.second && rightMin.second && (root->data > leftMax.first.second) && (root->data <= rightMin.first.first);
    pair<pair<int, int>, bool> ans;
    ans.first.first = minimum;
    ans.first.second = maximum;
    ans.second = isBSTAns;
    return ans;
}

bool isBST(BinaryTreeNode<int> *root)
{
    pair<pair<int, int>, bool> ans = isBSTHelper(root);
    return ans.second;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}