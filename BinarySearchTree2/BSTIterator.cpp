class BSTiterator
{
    stack<TreeNode<int>*> myStack;
    
    void pushAll(TreeNode<int>* node) {
        for(; node!=NULL; myStack.push(node), node= node->left);
    }
    public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushAll(root);
    }

    int next()
    {
        // write your code here
        TreeNode<int>* tmpNode= myStack.top();
        myStack.pop();
        pushAll(tmpNode-> right);
        return tmpNode->data;
    }

    bool hasNext()
    {
        // write your code here
        return !myStack.empty();
    }
};
