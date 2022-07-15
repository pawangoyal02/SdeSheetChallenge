// Leetcode

class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1;
        while(!st.empty() && st.top().first<=price)
        {
            count+=st.top().second;
            st.pop();
        }
        st.push({price,count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


// Codestudio

#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int,int>> st;
    vector<int> ans;
    for(int i=0; i<price.size(); i++)
    {
        int count=1;
        while(!st.empty() && st.top().first<=price[i])
        {
            count+=st.top().second;
            st.pop();
        }
        st.push({price[i],count});
        ans.push_back(count);
    }
    return ans;
}
