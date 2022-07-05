#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if(root == NULL) {
            return;
        }
        queue<BinaryTreeNode< int > *> q;
        q.push(root);
        
        while(!q.empty()) {
            int size= q.size();
            for(int i=0; i<size; i++) {
                BinaryTreeNode< int >* node= q.front();
                q.pop();
                if(i==size-1) {
                    node->next = NULL;
                } 
                else {
                    node->next= q.front();
                } 
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
}