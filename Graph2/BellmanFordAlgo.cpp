// GFG- Distance from the source

vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dist(V,1e8);
       vector<int> visited(V,0);
       dist[S]=0;
       for(int i=0;i<V-1;i++)
       {
           for(auto it : adj)
           {
               int u=it[0];
               int v=it[1];
               int w=it[2];
               if(dist[v]> (dist[u]+w))
               dist[v]=dist[u]+w;
           }
       }
       return dist;
    }

// Codestudio

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    for(int i = 1; i <= n; i++){
        for(auto it: edges){
            if(dist[it[0]] != 1e9 && dist[it[0]] + it[2] < dist[it[1]])
                dist[it[1]] = dist[it[0]] + it[2];
        }
    }
    return dist[dest];
}