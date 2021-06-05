#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
void printPostOrder(Node *root);
void printPreOrder(Node *root);
void printInOrder(Node *root);
void printLevelOrder(Node *root);
void insertInBT(Node *temp, int key);
void leftView(Node *root);
void rightView(Node *root);
Node *BT_from_PreIn(int *Pre, int *In, int start, int end);
//todo right top bottom view of Bt
int main()
{

    int inorder[] = {20, 10, 40, 30, 50};
    int preorder[] = {10, 20, 30, 40, 50};

    Node *root = BT_from_PreIn(preorder, inorder, 0, 4);
    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // rightView(root);
    // cout << "Preorder traversal of binary tree is \n";
    // printPreOrder(root);

    // cout << "\nInorder traversal of binary tree is \n";
    printInOrder(root);

    // cout << "\nPostorder traversal of binary tree is \n";
    // printPostOrder(root);

    // cout << "\nPrintLevelOrder Traversal on BT \n";
    // printLevelOrder(root);
    // cout << "\n";
    // insertInBT(root, 15);
    // printLevelOrder(root);

    return 0;
}

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}
void printPreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
void printInOrder(Node *root)
{
    if (root == NULL)
        return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}
void printLevelOrder(Node *root)

{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != nullptr)
        {
            q.push(temp->left);
        }
        if (temp->right != nullptr)
        {
            q.push(temp->right);
        }
    }
}
void insertInBT(Node *temp, int key)
{
    queue<Node *> q;
    q.push(temp);
    while (q.empty() == false)
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left == nullptr)
        {
            Node *newp = new Node(key);
            temp->left = newp;
            break;
        }
        else
            q.push(temp->left);
        if (temp->right == nullptr)
        {
            Node *newp = new Node(key);
            temp->right = newp;
            break;
        }
        else
            q.push(temp->right);
    }
}
void leftViewUtil(Node *root, int level, int *maxL)
{
    if (root == NULL)
        return;
    if (*maxL < level)
    {
        cout << root->data << " ";
        *maxL = level;
    }
    leftViewUtil(root->left, level + 1, maxL);
    leftViewUtil(root->right, level + 1, maxL);
}
void leftView(Node *root)
{
    int maxL = 0;
    leftViewUtil(root, 1, &maxL);
}
void RightViewUtil(Node *root, int level, int *maxL)
{
    if (root == NULL)
        return;
    if (*maxL < level)
    {
        cout << root->data << " ";
        *maxL = level;
    }
    RightViewUtil(root->right, level + 1, maxL);
    RightViewUtil(root->left, level + 1, maxL);
}
void rightView(Node *root)
{
    int maxL = 0;
    RightViewUtil(root, 1, &maxL);
}

int Root_Index = 0;

Node *BT_from_PreIn(int *Pre, int *In, int start, int end)
{
    if (end < start)
        return nullptr;
    Node *root = new Node(Pre[Root_Index++]);
    //Finding index of elem Pre[Root_Index] in inorder list and saving index to INindex
    int inIndex;
    for (int i = 0; i <= end; i++)
    {
        if (root->data == In[i])
        {
            inIndex = i;
            break;
        }
    }
    root->left = BT_from_PreIn(Pre, In, start, inIndex - 1);
    root->right = BT_from_PreIn(Pre, In, inIndex + 1, end);
    return root;
}