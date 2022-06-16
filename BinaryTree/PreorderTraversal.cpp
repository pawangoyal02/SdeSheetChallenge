void preorder(TreeNode* root, vector<int> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        ans.push_back(root->data);
        preorder(root->left, ans);
        preorder(root->right, ans);
        
    }
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
        vector<int> ans;
        preorder(root, ans);
        return ans;
}