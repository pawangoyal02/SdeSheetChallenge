#include<bits/stdc++.h>
struct Node{
    Node* links[2];
    
    bool containsKey(int ind){
        return (links[ind]!=NULL);
    }
    
    Node* get(int ind){
        return links[ind];
    }
    
    void put(int ind, Node* node){
        links[ind]= node;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root= new Node();
    }
    
    void insert(int num){
        Node* node= root;
        for(int i=31; i>=0; i--){
            int bit= (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node= node->get(bit);
        }
    }
    
    int findMax(int num){
        Node* node= root;
        int maxNum=0;
        for(int i=31; i>=0; i--){
            int bit= (num>>i)&1;
            if(node->containsKey(!bit)){
                maxNum= maxNum | (1<<i);
                node= node->get(!bit);
            }
            else
            {
                node= node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> offlineQueries;
        int q= queries.size();
        
        for(int i=0; i<q; i++)
        {
            offlineQueries.push_back({queries[i][1],{queries[i][0],i}});
        }
          sort(offlineQueries.begin(), offlineQueries.end());
        
        vector<int> ans(q,0);
        int ind=0;
        int n= nums.size();
        Trie trie;
        
        for(int i=0; i<q; i++){
            int ai= offlineQueries[i].first;
            int xi= offlineQueries[i].second.first;
            int qInd= offlineQueries[i].second.second;
            while(ind<n && nums[ind]<= ai){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind==0) ans[qInd]=-1;
            else ans[qInd]= trie.findMax(xi);
        }
        return ans;
    }
};