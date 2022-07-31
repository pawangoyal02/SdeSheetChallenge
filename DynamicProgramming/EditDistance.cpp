int recur(string &str1, string &str2,int i,int j)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(str1[i]==str2[j]) return recur(str1,str2,i-1,j-1);
    return 1+min(recur(str1,str2,i-1,j),min(recur(str1,str2,i-1,j-1),recur(str1,str2,i,j-1)));
}

int memo(string &str1, string &str2,int i,int j,vector<vector<int>> &dp)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(str1[i]==str2[j]) return dp[i][j]=memo(str1,str2,i-1,j-1,dp);
    return dp[i][j]=1+min(memo(str1,str2,i-1,j,dp),min(memo(str1,str2,i-1,j-1,dp),memo(str1,str2,i,j-1,dp)));
}

int tabu(string &s1,string &s2)
{
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++)
    {
        dp[0][j]=j;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=i;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        }
    }
    return dp[n][m];
}

int tabuso(string &s1,string &s2)
{
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<int> prev(m+1,0),curr(m+1,0);
    for(int j=0;j<=m;j++)
    {
        prev[j]=j;
    }
    
    for(int i=1;i<=n;i++)
    {
        curr[0]=i;
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1]) curr[j]=prev[j-1];
            else curr[j]=1+min(prev[j],min(prev[j-1],curr[j-1]));
        }
        prev=curr;
    }
    return prev[m];
}

int editDistance(string str1, string str2)
{
    //write you code here
    int n=str1.size(),m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//     return recur(str1,str2,n-1,m-1);
//     return memo(str1,str2,n-1,m-1,dp);
//     return tabu(str1,str2);
    return tabuso(str1,str2);

}