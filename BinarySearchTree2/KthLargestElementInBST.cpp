TreeNode<int>* kLargest(TreeNode<int>* root, int &k) {
        if(root==NULL) {
            return NULL;
        }
        TreeNode<int>* right= kLargest(root->right, k);
        if(right!=NULL) {
            return right;
        }
        k--;
        if(k==0) {
            return root;
        }
        return kLargest(root->left, k);
    }
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    TreeNode<int>* node= kLargest(root, k);
        return node->data;
}
