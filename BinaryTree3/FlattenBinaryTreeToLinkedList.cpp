TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int>* cur= root;
    TreeNode<int>* pre;
        while(cur) {
            if(cur->left) {
                pre= cur->left;
                while(pre->right) {
                    pre= pre->right;
                }
                pre->right= cur->right;
                cur->right= cur->left;
                cur->left= NULL;
            }
            cur= cur->right;
        }
    return root;
}