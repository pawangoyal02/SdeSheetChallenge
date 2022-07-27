#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	map<int,int> mp;
    vector<int> ans;
    for(int i=0; i<k; i++)
    {
        mp[arr[i]]++;
    }
    ans.push_back(mp.size());
    for(int i=k; i<arr.size(); i++)
    {
        if(mp[arr[i-k]]==1)
        {
            mp.erase(arr[i-k]);
        }
        else
        {
            mp[arr[i-k]]--;
        }
        mp[arr[i]]++;
        ans.push_back(mp.size());
    }
    return ans;
}
