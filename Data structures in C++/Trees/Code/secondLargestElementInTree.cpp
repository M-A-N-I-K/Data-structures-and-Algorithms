/*
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :

The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :

The first and only line of output contains data of the node with second largest data.

Constraints:

Time Limit: 1 sec

Sample Input 1 :

10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1 :

40
*/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
/*
First Approach :
class Pair
{
public:
    TreeNode<int> *max;
    TreeNode<int> *secMax;
};
Pair *getSecondLargestNodeHelper(TreeNode<int> *root)
{
    Pair *ans = new Pair();
    ans->max = root;
    ans->secMax = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        Pair *smallAns = getSecondLargestNodeHelper(root->children[i]);
        if (smallAns->max->data > ans->max->data)
        {
            if (smallAns->secMax == NULL)
            {
                ans->secMax = ans->max;
                ans->max = smallAns->max;
            }
            else
            {
                if (smallAns->secMax->data > ans->max->data)
                {
                    ans->secMax = smallAns->secMax;
                    ans->max = smallAns->max;
                }
                else
                {
                    ans->secMax = ans->max;
                    ans->max = smallAns->max;
                }
            }
        }
        else
        {
            if ((ans->max->data != smallAns->max->data) && (ans->secMax == NULL || smallAns->max->data > ans->secMax->data))
            {
                ans->secMax = smallAns->max;
            }
        }
    }
    return ans;
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Pair *ans = getSecondLargestNodeHelper(root);
    return ans->secMax;
}
*/
// Second Approach
class Pair
{
public:
    TreeNode<int> *largest;
    TreeNode<int> *secondLargest;
};
void helper(TreeNode<int> *root, Pair &ans)
{
    if (ans.secondLargest == NULL && ans.largest == NULL)
    {
        ans.largest = root;
        ans.secondLargest = NULL;
    }
    else
    {
        if (ans.secondLargest == NULL)
        {
            if (ans.largest->data > root->data)
            {
                ans.secondLargest = root;
            }
            else if (ans.largest->data == root->data)
            {
                // Nothing to so ans largest -> data == root -> data
            }
            else
            {
                ans.secondLargest = ans.largest;
                ans.largest = root;
            }
        }
        else
        {
            if (ans.secondLargest->data < root->data && ans.largest->data > root->data)
            {
                ans.secondLargest = root;
            }
            else if (ans.largest->data < root->data)
            {
                ans.secondLargest = ans.largest;
                ans.largest = root;
            }
        }
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        helper(root->children[i], ans);
    }
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    Pair ans;
    ans.largest = NULL;
    ans.secondLargest = NULL;
    helper(root, ans);
    return ans.secondLargest;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}