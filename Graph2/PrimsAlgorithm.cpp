// Brute Force- GFG

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int parent[V];
        int key[V];
        bool mstSet[V];
        for(int i=0; i<V; i++)
        {
            key[i]= INT_MAX;
            mstSet[i]= false;
            parent[i]= -1;
        }
        key[0]= 0;
        parent[0]= -1;
        for(int count=0; count<V-1; count++)
        {
            int mini= INT_MAX, u;
            for(int v=0; v<V; v++)
            {
                if(mstSet[v]==false && key[v]<mini)
                {
                    mini= key[v];
                    u= v;
                }
            }
            mstSet[u]= true;
            
            for(auto it: adj[u])
            {
                int v= it[0];
                int weight= it[1];
                if(mstSet[v]==false && weight<key[v])
                {
                    parent[v]= u;
                    key[v]= weight;
                }
            }
        }
        int sum= 0;
        for(int i=0; i<V; i++)
        {
            sum+= key[i];
        }
        return sum;
    }
};

// Optimal Solution- GFG

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int inf=1e9;
        vector<int> MST(V,-1);
        vector<int> key(V,inf);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        int sum=0;
        pq.push({0,0});
        key[0]=0;
        
        while(!pq.empty())
        {
            pair<int,int> top = pq.top();
            pq.pop();
            
            int node = top.second;
            if(MST[node]!=1) 
            {
                sum+=top.first;
                MST[node]=1;
            }
            else continue;
    
            for(auto neighbors : adj[node])
            {
                int v = neighbors[0];
                int wt = neighbors[1];
                
                if(MST[v]==-1 && wt < key[v]) 
                {
                    key[v]=wt;
                    pq.push({key[v],v});
                }
                
            }
        }
        return sum;
    }
};

// Codestudio

#include<bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)

{

   vector<pair<int,int>> adj[n+1];

for(auto it:g)

{

 adj[it.first.first].push_back({it.first.second,it.second});

 adj[it.first.second].push_back({it.first.first,it.second});

 //cout<<it.first.first<<" "<<it.first.second<<" "<<it.second;

}

   vector<int> parent(n+1,-1);

vector<int> key(n+1,INT_MAX);

vector<bool> mst(n+1,false);

key[1]=0;

parent[1]=-1;

for(int i=0;i<n-1;i++)

{

 int mini=INT_MAX,u;

 for(int i=1;i<=n;i++)

 {

  if(mst[i]==false and key[i]<mini)

  {

   mini=key[i],u=i;

  }

 }

 mst[u]=true;

 for(auto it:adj[u])

 {

  int first=it.first;

  int weight=it.second;

  if(mst[first]==false and weight<key[first])

  {

   key[first]=weight;

   parent[first]=u;

  }

 }

}

vector<pair<pair<int, int>, int>> ans;

for(int i=1;i<=n;i++)

{

 if(parent[i]!=-1)

 ans.push_back({{i,parent[i]},key[i]});

}

return ans;

}