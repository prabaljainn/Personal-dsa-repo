#include <bits/stdc++.h>
using namespace std;

class BSTnode
{
public:
    int data;
    BSTnode *left, *right;
};
BSTnode *GetNewNode(int data); //* GETnew node Return spointer to a new node with data
BSTnode *insterBST(BSTnode *root, int data);
void printInOrder(BSTnode *root);
int FindMinBST(BSTnode *root);
int FindMaxBST(BSTnode *root);
int heightBST(BSTnode *root);
bool isBST(BSTnode *root);
bool followsCSumP(BSTnode *root);
BSTnode *deleteBSTnode(BSTnode *root, int data);
BSTnode *findLCA(BSTnode *root, int n1, int n2);
int isBTbalanced(BSTnode *root);
int maxwidthBT(BSTnode *root);
bool searchBST(BSTnode *root, int data);
BSTnode *floor(BSTnode *root, int data); //* floor : value lesser or equal to the given key and the largest amongst
BSTnode *ceil(BSTnode *root, int data);  //* ceil: greater or equal to the given key and Smallest among the
void VerticleSumBT(BSTnode *root);       //* Verticle sum is the sum of all elem in the same horizontal distance in a bt
void VerticleTraversal(BSTnode *root);
void Top_View(BSTnode *root);
void Bottom_View(BSTnode *root);
void getnew();
void newfun();
int main()
{
    BSTnode *root = nullptr;
    root = insterBST(root, 12);
    root = insterBST(root, 15);
    root = insterBST(root, 10);
    root = insterBST(root, 25);
    root = insterBST(root, 8);
    root = insterBST(root, 11);
    Bottom_View(root);
}

BSTnode *GetNewNode(int data)
{
    BSTnode *temp = new BSTnode();
    temp->data = data;
    temp->left = temp->right = nullptr;

    return temp;
}
BSTnode *insterBST(BSTnode *root, int data)
{
    if (root == nullptr)
        root = GetNewNode(data);
    else if (data <= root->data)
        root->left = insterBST(root->left, data);

    else
        root->right = insterBST(root->right, data);
    return root;
}
void printInOrder(BSTnode *root)
{
    if (root == NULL)
        return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}
int FindMinBST(BSTnode *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root->data;
}
int FindMaxBST(BSTnode *root)
{
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->data;
}
int heightBST(BSTnode *root)
{
    if (root == nullptr)
        return -1;
    return max(heightBST(root->left), heightBST(root->right)) + 1;
}
bool isBSTutil(BSTnode *root, int min, int max)
{
    if (root == nullptr)
        return true;
    if (root->data < max && root->data > min && isBSTutil(root->left, min, root->data) && isBSTutil(root->right, root->data, max))
        return true;
    else
        return false;
}
bool isBST(BSTnode *root)
{
    return isBSTutil(root, INT_MIN, INT_MAX);
}
BSTnode *deleteBSTnode(BSTnode *root, int data)

{
    if (root == nullptr)
        return root;
    else if (root->data > data)
        root->left = deleteBSTnode(root->left, data);
    else if (root->data < data)
        root->right = deleteBSTnode(root->right, data);
    else
    { //* We found the elem
        //* case 1: it's a leaf node;
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        //* case 2: if its a node with 1 child
        else if (root->left == NULL && root->right != NULL)
        {
            BSTnode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            BSTnode *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            int rightmin = FindMinBST(root->right);
            root->data = rightmin;
            root->right = deleteBSTnode(root->right, rightmin);
        }
    }
    return root;
}

BSTnode *findLCA(BSTnode *root, int n1, int n2)
{
    if (root == nullptr)
        return nullptr;
    if (root->data == n1 || root->data == n2)
        return root;
    BSTnode *left_LCA = findLCA(root->left, n1, n2);
    BSTnode *right_LCA = findLCA(root->right, n1, n2);
    if (left_LCA && right_LCA)
        return root;
    return root->left == nullptr ? right_LCA : left_LCA;
}
bool followsCSumP(BSTnode *root)
{
    if (root == nullptr)
        return true;
    if (root->left == nullptr && root->right == nullptr)
        return true;
    int sum = 0;
    if (root->left != nullptr)
        sum += root->left->data;
    if (root->right != nullptr)
        sum += root->right->data;
    if (root->data == sum && followsCSumP(root->left) && followsCSumP(root->right))
        return true;
    else
        return false;
}
int isBTbalanced(BSTnode *root)
{

    if (root == nullptr)
        return 0;
    int l1 = isBTbalanced(root->left);
    int r1 = isBTbalanced(root->right);
    if (l1 == -1 || r1 == -1)
        return -1;
    if (abs(l1 - r1) > 1)
        return -1;
    else
        return (max(l1, r1) + 1);
}
int maxwidthBT(BSTnode *root)
{
    if (root == nullptr)
        return 0;
    int maxwidth = 0;
    queue<BSTnode *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        maxwidth = max(maxwidth, count);
        for (int i = 0; i < q.size(); i++)
        {
            BSTnode *temp = q.front();
            q.pop();
            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
        }
    }
    return maxwidth;
}
bool searchBST(BSTnode *root, int data)
{
    if (root == nullptr)
        return false;
    if (data == root->data)
        return true;
    if (data > root->data)
        return searchBST(root->right, data);
    if (data < root->data)
        return searchBST(root->left, data);
}
BSTnode *floor(BSTnode *root, int data)
{
    BSTnode *temp = nullptr;
    while ((root != nullptr))
    {
        if (root->data == data)
            return root;
        else if (root->data > data)
            root = root->left;
        else
        {
            temp = root;
            root = root->right;
        }
    }
    return temp;
}
BSTnode *ceil(BSTnode *root, int data)
{
    BSTnode *temp = nullptr;
    while (root != nullptr)
    {
        if (root->data > data)
        {
            temp = root;
            root = root->left;
        }
        else if (root->data == data)
            return root;
        else // root->data < data
            root = root->right;
    }
    return temp;
}

void VSU(BSTnode *root, int horizontal_d, map<int, int> &m)
{
    if (root == nullptr)
        return;
    VSU(root->left, horizontal_d - 1, m);
    m[horizontal_d] += root->data;
    //* Key POINT: yaha     m[horizontal_d] += root->data;  line beech mein aayi dono VSU ke kyuki pehele apan nein left mein traverse kiya jitna hua fir apan  us root ki value upadate ki fir right mein traverse kiya think of an example
    VSU(root->right, horizontal_d + 1, m);
}

void VerticleSumBT(BSTnode *root)
{
    map<int, int> verticle_distant_sum_MAP;
    VSU(root, 0, verticle_distant_sum_MAP);
    for (auto x : verticle_distant_sum_MAP)
        cout << x.second << " ";
}

void VerticleTraversal(BSTnode *root)
{ //* it is important to use level order traversal in the following question
    map<int, vector<int>> result_MAP;
    queue<pair<BSTnode *, int>> q;
    q.push({root, 0});
    while (q.empty() == false)
    {
        auto temp = q.front();
        BSTnode *current = temp.first;
        int h_Dis = temp.second;
        result_MAP[h_Dis].push_back(current->data);
        q.pop();
        if (current->left != nullptr)
        {
            q.push({current->left, h_Dis - 1});
        }
        if (current->right != nullptr)
        {
            q.push({current->right, h_Dis + 1});
        }
    }
    for (auto x : result_MAP)
    {
        for (int y : x.second)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

void Top_View(BSTnode *root)
{ //* it is important to use level order traversal in the following question
    map<int, int> result_MAP;
    queue<pair<BSTnode *, int>> q;
    q.push({root, 0});
    while (q.empty() == false)
    {
        auto temp = q.front();
        BSTnode *current = temp.first;
        int h_Dis = temp.second;
        if (result_MAP.find(h_Dis) == result_MAP.end())
        {
            result_MAP[h_Dis] = current->data;
        }
        q.pop();
        if (current->left != nullptr)
        {
            q.push({current->left, h_Dis - 1});
        }
        if (current->right != nullptr)
        {
            q.push({current->right, h_Dis + 1});
        }
    }
    for (auto x : result_MAP)
    {
        cout << x.second << " ";
    }
}

void Bottom_View(BSTnode *root)
{ //* it is important to use level order traversal in the following question
    map<int, int> result_MAP;
    queue<pair<BSTnode *, int>> q;
    q.push({root, 0});
    while (q.empty() == false)
    {
        auto temp = q.front();
        BSTnode *current = temp.first;
        int h_Dis = temp.second;

        result_MAP[h_Dis] = current->data;
        q.pop();
        if (current->left != nullptr)
        {
            q.push({current->left, h_Dis - 1});
        }
        if (current->right != nullptr)
        {
            q.push({current->right, h_Dis + 1});
        }
    }
    for (auto x : result_MAP)
    {
        cout << x.second << " ";
    }
}
