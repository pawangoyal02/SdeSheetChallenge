void rec(TreeNode<int>* root, int level, vector<int> &ans)
 {
     if(root==NULL) return;
     
     if(ans.size()==level)
     {
         ans.push_back(root->data);
     }
     rec(root->left, level+1, ans);
     rec(root->right, level+1, ans);
 }
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
   rec(root, 0, ans);
   return ans;
}