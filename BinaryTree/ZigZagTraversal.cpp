#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    vector<vector<int>> result;
        if(root == NULL)
        {
            return ans;
        }
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        bool leftToRight= true;
        
        while(!q.empty())
        {
            int size= q.size();
            vector<int> row(size);
            for(int i=0; i<size; i++)
            {
                BinaryTreeNode<int>* node= q.front();
                q.pop();
                
                int index= leftToRight ? i : (size-1-i);
                row[index]= node->data;
                
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            leftToRight= !leftToRight;
            result.push_back(row);
        }
    
    for(auto it: result) {
        for(auto value: it) {
            ans.push_back(value);
        }
    }
    return ans;
}
