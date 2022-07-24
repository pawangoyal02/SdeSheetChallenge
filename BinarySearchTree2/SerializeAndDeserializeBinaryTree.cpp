// CodeStudio

#include <sstream>
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    if(root==NULL) {
            return "";
        }
        string s= "";
        queue<TreeNode<int>*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode<int>* curNode= q.front();
            q.pop();
            if(curNode == NULL) {
                s.append("#,");
            }
            else {
                s.append(to_string(curNode->data)+',');
            }
            
            if(curNode!=NULL) {
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    if(serialized.size()==0) {
            return NULL;
        }
        string data= serialized;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode<int>* root= new TreeNode<int>(stoi(str));
        queue<TreeNode<int>*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode<int>* node= q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str=="#") {
                node->left= NULL;
            }
            else {
                TreeNode<int>* leftNode= new TreeNode<int>(stoi(str));
                node->left= leftNode;
                q.push(leftNode);
            }
            
            getline(s, str, ',');
            if(str=="#") {
                node->right= NULL;
            }
            else {
                TreeNode<int>* rightNode= new TreeNode<int>(stoi(str));
                node->right= rightNode;
                q.push(rightNode);
            }
        }
        return root;
}

// Leetcode

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) {
            return "";
        }
        string s= "";
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* curNode= q.front();
            q.pop();
            if(curNode == NULL) {
                s.append("#,");
            }
            else {
                s.append(to_string(curNode->val)+',');
            }
            
            if(curNode!=NULL) {
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) {
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root= new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node= q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str=="#") {
                node->left= NULL;
            }
            else {
                TreeNode* leftNode= new TreeNode(stoi(str));
                node->left= leftNode;
                q.push(leftNode);
            }
            
            getline(s, str, ',');
            if(str=="#") {
                node->right= NULL;
            }
            else {
                TreeNode* rightNode= new TreeNode(stoi(str));
                node->right= rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};