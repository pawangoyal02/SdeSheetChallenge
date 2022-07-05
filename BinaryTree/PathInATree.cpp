

bool getPath(TreeNode<int>* root, vector<int> &arr ,int x)
{
    if(!root)
    {
        return false;
    }
    arr.push_back(root->data);

    if(root->data == x)
    {
        return true;
    }

    if(getPath(root->left, arr, x) || getPath(root->right, arr, x))
    {
        return true;
    }

    arr.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> arr;
    if(root==NULL)
    {
        return arr;
    }
    getPath(root, arr, x);
    return arr;
}
