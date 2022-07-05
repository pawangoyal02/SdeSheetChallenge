pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    BinaryTreeNode<int>* node= root;
    int suc=-1, pre=-1;
    
    while(node!=NULL) {
        if(key >= node->data) {
            node= node->right;
        }
        else {
            suc= node->data;
            node= node->left;
        }
    }
    
    node= root;
    
    while(node!=NULL) {
        if(key <= node->data) {
            node= node->left;
        }
        else {
            pre= node->data;
            node= node->right;
        }
    }
    return make_pair(pre, suc);
}
