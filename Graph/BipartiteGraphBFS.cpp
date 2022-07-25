// Leetcode 

class Solution {
public:
    bool bipartiteBfs(int src, vector<vector<int>>& graph, vector<int> color)
    {
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int node= q.front();
            q.pop();
            for(auto it: graph[node])
            {
                if(color[it]==-1)
                {
                    color[it]= 1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> color(n,-1);
        for(int i=0; i<n; i++)
        {
            if(color[i]==-1)
            {
                if(!bipartiteBfs(i,graph,color))
                {
                    return false;
                }
            }
        }
       return true; 
    }
};

// Codestudio

#include<bits/stdc++.h>
bool check_bipartite(int src, vector<int> adj[], vector<int> & color){
    color[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if(color[it] == color[node]) return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    // Write your code here.
    
    int n = edges[0].size();
    vector<int> adj[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(edges[i][j]==1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    vector<int> color(n, -1);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(check_bipartite(i,adj,color)==false) return false;
        }
    }
    return true;
}