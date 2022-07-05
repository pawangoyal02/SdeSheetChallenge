
bool isSymmetricHelp(BinaryTreeNode<int>* left, BinaryTreeNode<int>* right) {
        if(left==NULL || right==NULL)
        {
            return left==right;
        }
        
        if(left->data != right->data) {
            return false;
        }
        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    }
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    return root==NULL || isSymmetricHelp(root->left, root->right);
}