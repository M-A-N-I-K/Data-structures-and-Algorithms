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
pair<pair<int, int>, bool> isBST2Helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<pair<int, int>, bool> p;
        p.first.first = INT_MAX;
        p.first.second = INT_MIN;
        p.second = true;
        return p;
    }
    pair<pair<int, int>, bool> leftMax = isBST2Helper(root->left);
    pair<pair<int, int>, bool> rightMin = isBST2Helper(root->right);
    int minimum = min(root->data, min(leftMax.first.first, rightMin.first.first));
    int maximum = max(root->data, max(leftMax.first.second, rightMin.first.second));
    bool isBSTAns = leftMax.second && rightMin.second && (root->data > leftMax.first.second) && (root->data <= rightMin.first.first);
    pair<pair<int, int>, bool> ans;
    ans.first.first = minimum;
    ans.first.second = maximum;
    ans.second = isBSTAns;
    return ans;
}

bool isBST2(BinaryTreeNode<int> *root)
{
    pair<pair<int, int>, bool> ans = isBST2Helper(root);
    return ans.second;
}

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > max || root->data < min)
    {
        return false;
    }
    bool isLeftOK = isBST3(root->left, min, root->data - 1);
    bool isRightOK = isBST3(root->right, root->data, max);
    return isLeftOK && isRightOK;
}

vector<int> *findPathBinaryTree(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }
    vector<int> *leftVec = findPathBinaryTree(root->left, data);
    if (leftVec != NULL)
    {
        leftVec->push_back(root->data);
        return leftVec;
    }
    vector<int> *rightVec = findPathBinaryTree(root->right, data);
    if (rightVec != NULL)
    {
        rightVec->push_back(root->data);
        return rightVec;
    }
    else
    {
        return NULL;
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    vector<int> *vec = findPathBinaryTree(root, 7);
    for (int i = 0; i < vec->size(); i++)
    {
        cout << vec->at(i) << " ";
    }
    delete vec;
}