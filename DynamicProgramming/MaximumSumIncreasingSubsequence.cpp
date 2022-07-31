int maxIncreasingDumbbellsSum(vector<int> &rack, int n){
    int dp[n] = {rack[0]}, result = rack[0];
    for(int i = 1; i<n; i++){
        dp[i] = rack[i];
        for(int j = 0; j<i; j++){
            if(rack[j]<rack[i])
                dp[i] = max(dp[i],rack[i] + dp[j]);
        }
        result = max(result,dp[i]);
    }
    return result;
}