/*
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.
Balanced Binary Tree:

A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.

Input format:

The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format

The first and only line of output contains true or false.

Constraints

Time Limit: 1 second

Sample Input 1 :

5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1 :

false

Sample Input 2 :

1 2 3 -1 -1 -1 -1

Sample Output 2 :

true

*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
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

// int height(BinaryTreeNode<int> *root){
//     if(root == 0){
//         return 0;
// 	}
//     return 1 + max(height(root->left) , height(root->right));
// }

pair<bool, int> isBalancedHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<bool, int> ans;
        ans.first = true;
        ans.second = 0;
        return ans;
    }
    pair<bool, int> ans;
    pair<bool, int> ans1 = isBalancedHelper(root->left);
    pair<bool, int> ans2 = isBalancedHelper(root->right);
    ans.second = 1 + max(ans1.second, ans2.second);
    if (abs(ans1.second - ans2.second) > 1)
    {
        ans.first = false;
    }
    else
    {
        ans.first = ans1.first && ans2.first;
    }
    return ans;
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    // if(root == NULL){
    // return true;
    // }
    // int leftHeight = height(root->left);
    // int rightHeight = height(root->right);
    // if(abs(leftHeight - rightHeight) > 1){
    // return false;
    // }
    // else{
    // bool ans1 = isBalanced(root->left);
    // bool ans2 = isBalanced(root->right);
    // return ans1 && ans2;
    // }
    pair<bool, int> ans = isBalancedHelper(root);
    return ans.first;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");
}