class Solution {
public:
    TreeNode* constructBST(vector<int> &nums, int start, int end) {
        if(start>end) {
            return NULL;
        }
        int mid= (start+end+1)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left= constructBST(nums, start, mid-1);
        root->right= constructBST(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size()-1);
    }
};