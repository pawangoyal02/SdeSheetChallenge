class Solution {

public:
int ans=0; //Declare answer globally
    
    int solve(TreeNode* root, int &maxi ,int &mini,int &isBST){
if(root==NULL){
maxi = INT_MIN ;
mini = INT_MAX ;
isBST = 1 ;
return 0;
}
int leftmaxi,leftmini,rightmaxi,rightmini,RisBST,LisBST;
//
int leftsum=solve(root->left,leftmaxi,leftmini,LisBST);
int rightsum=solve(root->right,rightmaxi,rightmini,RisBST);
//

   //check if the subtree is a valid BST or not
   if(leftmaxi < root->val and rightmini > root->val and LisBST and RisBST){
       isBST=1;
       ans=max(ans,leftsum + rightsum + root->val);
       
   }
   else isBST=0;
   
    mini = min(leftmini,root->val);
    maxi = max(rightmaxi,root->val);
   //
   return leftsum + rightsum + root->val;
}
    int maxSumBST(TreeNode* root) {
        int maxi = INT_MIN , mini=INT_MAX;
        int isBST=1;
        int sum=solve(root,maxi,mini,isBST);
        return ans;
    }
};