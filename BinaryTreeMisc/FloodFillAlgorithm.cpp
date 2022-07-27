class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &image,int newColor,int n,int m,int oldColor)
    {
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(vis[i][j] or image[i][j]!=oldColor) return;
        vis[i][j]=1;
        image[i][j]= newColor;
        dfs(i+1,j,vis,image,newColor,n,m,oldColor);
        dfs(i,j+1,vis,image,newColor,n,m,oldColor);
        dfs(i-1,j,vis,image,newColor,n,m,oldColor);
        dfs(i,j-1,vis,image,newColor,n,m,oldColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size();
        int m= image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int oldColor= image[sr][sc];
        int newColor= color;
        dfs(sr,sc,vis,image,newColor,n,m,oldColor);
        return image;
    }
};