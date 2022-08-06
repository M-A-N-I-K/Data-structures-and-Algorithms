#include <iostream>
#include <vector>
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

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data : " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter No. of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
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

int main()
{
    /*
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *child1 = new TreeNode<int>(2);
    TreeNode<int> *child2 = new TreeNode<int>(3);
    root->children.push_back(child1);
    root->children.push_back(child2);
    printTreeNodes(root);
    */
    TreeNode<int> *root = takeInput();
    printTreeNodes(root);
    return 0;
}