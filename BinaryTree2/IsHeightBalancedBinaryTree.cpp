int check(BinaryTreeNode<int>* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int lh= check(root->left);
        int rh= check(root->right);
        
        if(lh==-1 || rh== -1)
        {
            return -1;
        }
        
        if(abs(lh-rh)>1)
        {
            return -1;
        }
        
        return 1+max(lh,rh);
    }
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return check(root)!= -1;
}