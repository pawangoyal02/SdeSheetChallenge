#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}
int main() {
    int n=6, m=7;
	vector<int> adj[n+1]; 
	adj[1].push_back(3);
	adj[2].push_back(1);
	adj[3].push_back(2);
	adj[3].push_back(5);
	adj[4].push_back(6);
	adj[5].push_back(4);
	adj[6].push_back(5);
	
	stack<int> st;
	vector<int> vis(n+1, 0); 
	for(int i = 1;i<=n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 
	
	vector<int> transpose[n+1]; 
	
	for(int i = 1;i<=n;i++) {
	    vis[i] = 0; 
	    for(auto it: adj[i]) {
	        transpose[it].push_back(i); 
	    }
	}
	
	while(!st.empty()) {
	    int node = st.top();
	    st.pop(); 
	    if(!vis[node]) {
	        cout << "SCC: "; 
	        revDfs(node, vis, transpose); 
	        cout << endl; 
	    }
	}
	
	return 0;
}

// Codestudio- Tarjans Algo

#include<bits/stdc++.h>
void dfs(int s, vector<int> &vis,vector<int> adj[], stack<int> &st){
   vis[s]=1;
   for(auto it : adj[s]){
       if(!vis[it])
           dfs(it,vis,adj,st);
   }
   st.push(s);
}
void revdfs(int s,vector<int> &vis,vector<int> tra[],vector<int> &res){
   vis[s]=1;
   res.push_back(s);
   for(auto it:tra[s]){
       if(!vis[it]){
           revdfs(it, vis, tra,res);
       }
   }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> ans;
   vector<int> vis(n,0);
   vector<int> adj[n];
   vector<int> tra[n];
   stack<int> st;
   for(auto it:edges){
       adj[it[0]].push_back(it[1]);
   }
   for(int i=0;i<n;i++){
       if(!vis[i]){
           dfs(i,vis,adj,st);
       }
   }
   for(int i=0;i<n;i++){
       vis[i]=0;
       for(auto it: adj[i]){
           tra[it].push_back(i);
       }
   }
   while(!st.empty()){
       int a=st.top();
       st.pop();
       if(!vis[a]){
           vector<int> res;
           revdfs(a,vis,tra,res);
           ans.push_back(res);
       }
   }
   return ans;
}