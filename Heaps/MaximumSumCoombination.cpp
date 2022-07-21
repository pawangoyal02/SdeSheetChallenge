#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int C){
	// Write your code here.
    sort(A.begin(), A.end(), greater<int> ());
    sort(B.begin(), B.end(), greater<int> ());
    vector<int> ans;
    set<pair<int,int>> s;
    priority_queue<pair<int, pair<int,int>>> pq;
    pq.push({A[0]+B[0],{0,0}});
    for(int i=0; i<C; i++)
    {
        auto p= pq.top();
        pq.pop();
        ans.push_back(p.first);
        
        if(p.second.first+1<A.size() && s.find({p.second.first+1, p.second.second})==s.end())
        {
            pq.push({A[p.second.first+1]+B[p.second.second],{p.second.first+1,p.second.second}});
            s.insert({p.second.first+1,p.second.second});
        }
        
        if(p.second.second+1<A.size() && s.find({p.second.first, p.second.second+1})==s.end())
        {
            pq.push({A[p.second.first]+B[p.second.second+1],{p.second.first,p.second.second+1}});
            s.insert({p.second.first,p.second.second+1});
        }
    }
    return ans;
}