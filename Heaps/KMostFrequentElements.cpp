// Leetcode
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;

        for(auto it:nums)
            mp[it]++;
    
        for(auto it:mp)
        pq.push({it.second, it.first});

        vector<int> ans;
        while(k--){
            auto x=pq.top();
            ans.push_back(x.second);
            pq.pop();
        }
        return ans;   
    }
};


//Codestudio
#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
    // Write your code here.
    priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;

        for(auto it:nums)
            mp[it]++;
    
        for(auto it:mp)
        pq.push({it.second, it.first});

        vector<int> ans;
        while(k--){
            auto x=pq.top();
            ans.push_back(x.second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;  
}