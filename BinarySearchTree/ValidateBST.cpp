// CodeStudio
//Code 1
#include<bits/stdc++.h>
void inorder(BinaryTreeNode<int> *root,vector<int>&v){
    if(root){
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
        
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
   vector<int>v;
    inorder(root,v);
    for(int i=1;i<v.size();i++){
        if(v[i]<v[i-1]){
            return false;
        }
    }
    return true;
}

//Code 2
bool checkBST(BinaryTreeNode<int>* root, int mn, int mx)
    {
        if(root==NULL)
            return true;
        
        if(root->data>=mn && root->data<=mx)
        {
 return checkBST(root->left,mn,root->data)&&checkBST(root->right,root->data,mx);
        }
        else
        {
            return false;
        }
    }

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return checkBST(root,INT_MIN,INT_MAX);  
}

//Leetcode
//Code 3
class Solution {
public:
    bool isValidBSTHelp(TreeNode* root, long minVal, long maxVal) {
        if(root==NULL) {
            return true;
        }
        if(root->val >=maxVal || root->val <=minVal) {
            return false;
        }
        return isValidBSTHelp(root->left, minVal, root->val) && isValidBSTHelp(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelp(root, LONG_MIN, LONG_MAX);
    }
};