// Code

class Solution {

  public:
    bool checkForCycle(int node, int parent, vector < int > & vis, vector < int > adj[]) {
      vis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkForCycle(it, node, vis, adj))
            return true;
        } else if (it != parent)
          return true;
      }

      return false;
    }
  public:
    bool isCycle(int V, vector < int > adj[]) {
      vector < int > vis(V + 1, 0);
      for (int i = 0; i < V; i++) {
        if (!vis[i]) {
          if (checkForCycle(i, -1, vis, adj)) return true;
        }
      }

      return false;
    }
};

//Codestudio

bool isCyclic(vector<int> adj[],vector<int> &vis,int v,int parent){

    vis[v] =1;
    for(int child : adj[v]){
        if(!vis[child]){
            if(isCyclic(adj,vis,child,v)) return true;
        }
        else if(child != parent){
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];
    for(int i=0; i<m; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(n+1,0);
    
    for(int i =1;i<=n;i++){
        if(!vis[i] && isCyclic(adj,vis,i,-1)){
            return "Yes";
        }
    }
    return "No";
}
