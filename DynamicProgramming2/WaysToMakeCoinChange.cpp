#include<bits/stdc++.h>
long func(int ind, int value, int *a, vector<vector<long>> &dp) {
    if(ind==0)
    {
        return (value%a[0]==0);
    }
    if(dp[ind][value]!=-1) return dp[ind][value];
    long notTake= func(ind-1,value, a, dp);
    long take=0;
    if(a[ind]<=value) take= func(ind, value-a[ind],a, dp);
    
    return dp[ind][value]= notTake + take;
        
}
long countWaysToMakeChange(int *a, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long> (value+1,-1));
    vector<long> prev(value+1,0), cur(value+1,0);
    for(int T=0; T<=value; T++) {
        prev[T]= (T%a[0]==0);
    }
    for(int ind=1; ind<n; ind++) {
        for(int T=0; T<=value; T++) {
            long notTake= prev[T];
            long take=0;
            if(a[ind]<=T) take= cur[T-a[ind]];
    
            cur[T]= notTake + take;
        }
        prev= cur;
    }
    //return func(n-1, value, denominations, dp);
    return prev[value];
}