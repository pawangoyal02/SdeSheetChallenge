vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size= q.size();
            
            for(int i=0; i<size; i++)
            {
                BinaryTreeNode<int>* node= q.front();
                q.pop();
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
                ans.push_back(node->val);
            }
        }
        return ans;
}