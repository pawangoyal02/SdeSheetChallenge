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


// Codestudio- Using the fact that inorder of BST is sorted

#include<bits/stdc++.h>
using namespace std;
void inorder(TreeNode<int>*root,vector<int> &ans){
    if(root==NULL)return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    vector<int> ans;
    inorder(root,ans);
    if(ans.size()<k)return -1;
    return ans[ans.size()-k];
    
}