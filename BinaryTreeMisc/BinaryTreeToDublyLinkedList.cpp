void help(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &prev, BinaryTreeNode<int>* &head) {
    // Write your code here
    if(root==NULL) return;
    help(root->left, prev, head);
    if(prev==NULL) head= root;
    else
    {
        root->left= prev;
        prev->right= root;
    }
    prev= root;
    help(root->right, prev, head);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* prev= NULL;
    BinaryTreeNode<int>* head= NULL;
    help(root, prev, head);
    return head;
}