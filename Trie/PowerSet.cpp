// Using Bit Manipluation

#include<bits/stdc++.h>
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    int n= v.size();
    vector<vector<int>> ans;
    for(int num=0; num<(1<<n); num++)
    {
        vector<int> a;
        for(int i=0; i<n; i++){
            if(num&(1<<i)){
                a.push_back(v[i]);
            }
        }
        if(a.size()>0)
        {
            ans.push_back(a);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

// Recursion & Backtracking

void solve(int i, vector<int>v, vector<int> &a, vector<vector<int>> &ans)
{
    if(i==v.size()){
        ans.push_back(a);
        return;
    }
    a.push_back(v[i]);
    solve(i+1,v,a,ans);
    a.pop_back();
    solve(i+1,v,a,ans);
}
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> ans;
    vector<int> a;
    solve(0,v,a,ans);
    return ans;
}

// GFG

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n= s.length();
    vector<string> ans;
    for(int num=0; num<(1<<n); num++)
    {
        string a="";
        for(int i=0; i<n; i++){
            if(num&(1<<i)){
                a+=s[i];
            }
        }
        if(a.length()>0)
        {
            ans.push_back(a);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
		}
};