class Solution {
public:
    TreeNode* kSmallest(TreeNode* root, int &k) {
        if(root==NULL) {
            return NULL;
        }
        TreeNode* left= kSmallest(root->left, k);
        if(left!=NULL) {
            return left;
        }
        k--;
        if(k==0) {
            return root;
        }
        return kSmallest(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node= kSmallest(root, k);
        return node->val;
    }
};