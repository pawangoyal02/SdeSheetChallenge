#include<bits/stdc++.h>
class BSTiterator
{
    stack<BinaryTreeNode<int>*> myStack;
    bool reverse= true;
    
    void pushAll(BinaryTreeNode<int>* node) {
        for(; node!=NULL;) {
            myStack.push(node);
            if(reverse == true) {
                node= node->right;
            }
            else {
                node= node->left;
            }
        }
    }
    public:
    BSTiterator(BinaryTreeNode<int> *root, bool isReverse)
    {
        // write your code here
        reverse= isReverse;
        pushAll(root);
    }

    int next()
    {
        // write your code here
        BinaryTreeNode<int>* tmpNode= myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode-> right);
        else pushAll(tmpNode->left);
        return tmpNode->data;
    }

    bool hasNext()
    {
        // write your code here
        return !myStack.empty();
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    if(!root) {
        return false;
    }
    BSTiterator l(root, false);
        //before
        BSTiterator r(root, true);
        
        int i= l.next();
        int j= r.next();
        
        while(i<j) {
            if(i+j==k) {
                return true;
            }
            else if(i+j<k) {
                i= l.next();
            }
            else {
                j= r.next();
            }
        }
        return false;
}