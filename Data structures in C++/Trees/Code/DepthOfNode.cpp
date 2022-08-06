#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;
    TreeNode(int data)
    {
        this->data = data;
    }
};

TreeNode<int> *takeInputLevelwise()
{
    int rootData;
    cout << "Enter Root Data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> PendingNodes;
    PendingNodes.push(root);
    while (PendingNodes.size() != 0)
    {
        TreeNode<int> *front = PendingNodes.front();
        PendingNodes.pop();
        cout << "Enter No. of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "Th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            PendingNodes.push(child);
        }
    }
    return root;
}

void printTreeNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTreeNodes(root->children[i]);
    }
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int countNodes(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNodes(root->children[i]);
    }
    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelwise();
    printAtLevelK(root, 2);
    return 0;
}