// CodeStudio
long long int solve(TreeNode<int> *root, long long int &ans) {
    if(!root) return 0;
    
    long long int l = solve(root->left, ans);
    long long int r = solve(root->right, ans);
    ans = max(ans, l+r+root->val);
    
    return max(l, r)+root->val;
}

long long int findMaxSumPath(TreeNode<int> *root) {
    if(!root) return -1;
    if(!root->left || !root->right) return -1;
    
    long long int ans = 0;
    solve(root, ans);
    return ans;
}

//Leetcode

class Solution {
public:
    int maxPathDown(TreeNode* root, int &maxi) {
        if(root==NULL) {
            return 0;
        }
        
        int left= max(0,maxPathDown(root->left, maxi));
        int right= max(0,maxPathDown(root->right, maxi));
        
        maxi= max(maxi, left+right+root->val);
        
        return (root->val) + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxi= INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};