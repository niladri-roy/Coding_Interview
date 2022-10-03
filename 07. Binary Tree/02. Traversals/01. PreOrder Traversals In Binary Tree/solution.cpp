// In preorder traversal, the tree is traversed in this way: root, left, right

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:

        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value)
        {
            this -> data = value;
            this -> left = NULL;
            this -> right = NULL;
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

void PreOrderRecursive(TreeNode* root, vector<int> &ans)
{
    // Base Case
    // If we encounter a node pointing to NULL.
    if(root == NULL)
    {
        // We simply return to its parent.
        return;
    }

    // We first visit the root node and before visiting its children 
    // We store its value in ans vector called by reference
    ans.push_back(root->data);

    // After this, we recursively visit its left child.
    PreOrderRecursive(root->left, ans);

    // After this, we recursively visit its right child.
    PreOrderRecursive(root->right, ans);
}

vector<int> PreOrderIterative(TreeNode* root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    // We first take an explicit stack data structure
    stack<TreeNode*> st;

    // Push the root node to it.(if the root node is not NULL).
    st.push(root);

    // Then we use a while loop to iterate over the stack till the stack 
    //remains non-empty.
    while(!st.empty())
    {
        // In every iteration we first pick and pop the stack’s top 
        TreeNode* curr = st.top();
        st.pop();

        // ans store the data of that node in ans vector
        ans.push_back(curr->data);

        // Then we first push the right child of this popped node and 
        // then push the left child, if they are not NULL. We do so 
        // because stack is a last-in-first-out(LIFO) data structure. 
        // We need to access the left child first, so we need to push it 
        // at the last.
        if(curr->right)
        {
            st.push(curr->right);
        }

        if(curr->left)
        {
            st.push(curr->left);
        }

        // The execution continues and will stop when the stack becomes empty. 
        // In this process, we will get the preorder traversal of the tree.
    }
    return ans;
}

void Print1D(vector<int> toPrint)
{
    int n = toPrint.size();

    for(int i=0; i<n; i++)
    {
        cout << toPrint[i] << " " ;
    }
    cout << endl;
}

int main()
{
    TreeNode *root = NULL;

    // creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    vector<int> ans1; 
    PreOrderRecursive(root, ans1);
    Print1D(ans1);

    vector<int> ans2 = PreOrderIterative(root);
    Print1D(ans2);


}
