bool func(int ind, int target, vector<int> &a, vector<vector<int>> &dp) {
    if(target==0) return true;
    if(ind==0) return(a[0]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notTake= func(ind-1,target,a,dp);
    bool take= false;
    if(target>=a[ind]){
        take= func(ind-1,target-a[ind],a,dp);
    }
    return dp[ind][target]= take or notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    return  func(n-1,k,arr,dp);
}