// Leetcode

class Solution {
public:
    void dfs(Node* node, Node* copy, vector<Node*> &vis)
    {
        vis[copy->val]= copy;
        for(auto x: node->neighbors)
        {
            if(vis[x->val]==NULL)
            {
                Node* newNode= new Node(x->val);
                (copy->neighbors).push_back(newNode);
                dfs(x,newNode,vis);
            }
            else
            {
                (copy->neighbors).push_back(vis[x->val]);
            }
        }
    }
        
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        vector<Node*> vis(1000,NULL);
        Node* copy= new Node(node->val);
        dfs(node,copy,vis);
        return copy;
    }
};

// Codestudio

void dfs(graphNode* node, graphNode* copy, vector<graphNode*> &vis)
    {
        for(auto x: node->neighbours)
        {
            if(vis[x->data]==NULL)
            {
                graphNode* newNode= new graphNode(x->data);
                vis[x->data]= newNode;
                (copy->neighbours).push_back(newNode);
                dfs(x,newNode,vis);
            }
            else
            {
                (copy->neighbours).push_back(vis[x->data]);
            }
        }
    }
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
    if(node==NULL) return NULL;
        vector<graphNode*> vis(100005,NULL);
        graphNode* copy= new graphNode(node->data);
        vis[copy->data]= copy;
        dfs(node,copy,vis);
        return copy;
}