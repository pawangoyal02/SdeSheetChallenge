#include<bits/stdc++.h>
TreeNode<int> * constructTree(vector<int> & preorder, int preStart, int preEnd, vector<int> & inorder, int inStart, int inEnd, map< int,int> & mp) {
  if (preStart > preEnd || inStart > inEnd) return NULL;

  TreeNode<int> * root = new TreeNode<int>(preorder[preStart]);
  int inroot = mp[root -> data];
  int numsLeft = inroot - inStart;

  root -> left = constructTree(preorder, preStart + 1, preStart + numsLeft, inorder,
  inStart, inroot - 1, mp);
  root -> right = constructTree(preorder, preStart + numsLeft + 1, preEnd, inorder, 
  inroot + 1, inEnd, mp);

  return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int preStart = 0, preEnd = preorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}