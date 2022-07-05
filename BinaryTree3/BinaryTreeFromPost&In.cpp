#include<bits/stdc++.h>
TreeNode<int>* buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &hm) {
        if(ps>pe || is>ie) {
            return NULL;
        }
        
        TreeNode<int>* root= new TreeNode<int>(postorder[pe]);
        
        int inRoot= hm[postorder[pe]];
        int numsLeft= inRoot-is;
        
        root->left= buildTreePostIn(inorder, is, inRoot-1, postorder, ps, ps+numsLeft-1, hm);
        root->right= buildTreePostIn(inorder, inRoot+1, ie, postorder, ps+numsLeft, pe-1, hm);
        
        return root;
    }
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	// Write your code here.
    if(inorder.size()!=postorder.size()) return NULL;
        
        map<int, int> hm;
        
        for(int i=0; i< inorder.size(); i++)
        {
            hm[inorder[i]]= i;
        }
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, hm);
}
