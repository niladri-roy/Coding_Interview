// In LevelOrder traversal, the tree is traversed in this way: root, left, right

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *buildTree(TreeNode *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new TreeNode(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for left node: " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for right node: " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void LevelOrderRecursive(TreeNode *root, vector<vector<int>> &ans, int height)
{
    vector<int> tempAns;
    if(root == NULL) return;

    
    
}

vector<vector<int>> LevelOrderIterative(TreeNode *root)
{
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> tempAns;
        for(int i=0; i<size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            tempAns.push_back(curr->data);

            if(curr->left)
            {
                q.push(curr->left);
            }

            if(curr->right)
            {
                q.push(curr->right);
            }
        }
        ans.push_back(tempAns);
    }
    return ans;
}

void Print1D(vector<vector<int>> toPrint)
{
    int n = toPrint.size();

    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<toPrint[i].size(); j++)
        {
            cout << toPrint[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    TreeNode *root = NULL;

    // creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    vector<vector<int>> ans1;
    LevelOrderRecursive(root, ans1, 1);
    Print1D(ans1);

    vector<vector<int>> ans2 = LevelOrderIterative(root);
    Print1D(ans2);
}
