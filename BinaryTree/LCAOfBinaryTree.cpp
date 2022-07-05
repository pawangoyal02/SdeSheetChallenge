TreeNode<int>* lowestCommonAncestorHelp(TreeNode<int>* root, int p, int q) {
        if(root==NULL || root->data==p || root->data==q)
        {
            return root;
        }
        
        TreeNode<int>* left= lowestCommonAncestorHelp(root->left, p, q);
        TreeNode<int>* right= lowestCommonAncestorHelp(root->right, p, q);
        
        if(left==NULL)
        {
            return right;
        }
        else if(right==NULL)
        {
            return left;
        }
        else // both left and right are not null
        {
            return root;
        }
    }
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    return lowestCommonAncestorHelp(root, x, y)->data;
}