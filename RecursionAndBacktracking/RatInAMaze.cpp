// GFG Sol-1

class Solution {
  void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }

    // downward
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
      vis[i][j] = 1;
      solve(i + 1, j, a, n, ans, move + 'D', vis);
      vis[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
      vis[i][j] = 1;
      solve(i, j - 1, a, n, ans, move + 'L', vis);
      vis[i][j] = 0;
    }

    // right 
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
      vis[i][j] = 1;
      solve(i, j + 1, a, n, ans, move + 'R', vis);
      vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
      vis[i][j] = 1;
      solve(i - 1, j, a, n, ans, move + 'U', vis);
      vis[i][j] = 0;
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));

      if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis);
      return ans;
    }
};

// GFG Sol-2

class Solution {
  void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
        vis[i][j] = 1;
        solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
        vis[i][j] = 0;
      }
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));
      int di[] = {
        +1,
        0,
        0,
        -1
      };
      int dj[] = {
        0,
        -1,
        1,
        0
      };
      if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
      return ans;
    }
};

// Codestudio- Rat in a Maze all paths

void helper(vector<vector<int>> &m, int n, int r, int c,vector<vector<int>> &ans,vector<vector<int>> vis){
        //cout<<"r: "<<r<<" c: "<<c<<endl;
        if(!m[r][c]){
            return;
        }
        if(r==(n-1) && c==(n-1)){
            //cout<<"r & c"<<r<<" "<<c<<" p: "<<p<<endl;
             vis[r][c]=1;
             vector<int> temp;   
            //ans.push_back(p);
            for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(vis[i][j]);
            }
        }
            ans.push_back(temp);
      
            return;
        }
        m[r][c]=0;
        vis[r][c]=1;
        if(r<n-1){
            helper(m,n,r+1,c,ans,vis);
            }
        if(c<n-1){
            helper(m,n,r,c+1,ans,vis);
        }
        if(r>0){
            helper(m,n,r-1,c,ans,vis);
            }
        
        if(c>0){
            helper(m,n,r,c-1,ans,vis);
            }
        
        m[r][c]=1;
        vis[r][c]=0;
    }
vector<vector<int>> ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> vis(n, vector<int> (n,0));
    vector<int> temp;
    helper(maze,n,0,0,ans,vis);
    sort(ans.begin(),ans.end());
    return ans;
}