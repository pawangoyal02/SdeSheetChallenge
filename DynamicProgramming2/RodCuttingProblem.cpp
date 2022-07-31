int func(int ind, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if(ind==0) {
        return n*price[0];
    }
    if(dp[ind][n]!=-1) return dp[ind][n];
    int notTake= 0 + func(ind-1, n, price,dp);
    int take= 0;
    int rodLen= ind+1;
    if(rodLen<=n) take= price[ind] + func(ind,n-rodLen, price,dp);
    return dp[ind][n]= max(take,notTake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n, vector<int>(n+1,-1));
    vector<int> prev(n+1,0), cur(n+1,0);
    for(int N=0; N<=n; N++) {
        //dp[0][N]= N*price[0];
        prev[N]= N*price[0];
    }
    
    for(int ind=1; ind<n; ind++) {
        for(int N=0; N<=n; N++) {
            //int notTake= 0 + dp[ind-1][N];
            int notTake= 0 + prev[N];
            int take= INT_MIN;
            int rodLen= ind+1;
            //if(rodLen<=N) take= price[ind] + dp[ind][N-rodLen];
            //if(rodLen<=N) take= price[ind] + cur[N-rodLen];
            if(rodLen<=N) take= price[ind] + prev[N-rodLen];
            //dp[ind][N]= max(take,notTake);
            //cur[N]= max(take,notTake);
            prev[N]= max(take,notTake);
        }
        //prev= cur;
    }
    //return dp[n-1][n];
    return prev[n];
    //return func(n-1,n,price,dp);
}
