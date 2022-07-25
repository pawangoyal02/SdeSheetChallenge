class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
        }
        
        vector<int> indegree(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            for(auto nbr: adj[i]){
                indegree[nbr]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int visited = 0;
        
        while(!q.empty()){
            int top = q.front(); q.pop();
            visited++;
            for(auto nbr: adj[top]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        
        if(visited == numCourses) return true;
        return false;
    }
};