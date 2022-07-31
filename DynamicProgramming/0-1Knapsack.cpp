#include<bits/stdc++.h>
int func(int ind, int w, vector<int> &values, vector<int> &weights, vector<vector<int>> &dp) {
    if(ind==0) {
        if(weights[0]<=w) return values[0];
        else return 0;
    }
    if (dp[ind][w]!=-1) return dp[ind][w];
     int notTake= 0 + func(ind-1,w,values,weights,dp);
    int take= INT_MIN;
    if(weights[ind]<=w) take= values[ind] + func(ind-1,w-weights[ind],values, weights,dp);
    return dp[ind][w]= max(take,notTake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int>> dp(n, vector<int>(w+1,-1));
    return func(n-1,w,values,weights,dp);
}