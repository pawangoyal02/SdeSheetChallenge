// Leetcode

class MedianFinder {
public:
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max.empty() || max.top()>num) max.push(num);
        else min.push(num);
        int diff=max.size()-min.size();
        if(abs(diff) > 1){
            if(max.size()>min.size()){
                min.push(max.top());
                max.pop();
            }else{
                max.push(min.top());
                min.pop();
            }
        }
    }
    
    double findMedian() {
        double ans;
        if(max.size()==min.size()){
            ans=(max.top()+min.top())/2.0;
        }else{
            if(max.size()>min.size()) ans=max.top();
            else ans=min.top();
        }
        return ans;
    }
};

// CodeStudio

#include <bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n)
{
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;
    if(n==0)
        return;
    s.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++)
    {
        int x=arr[i];
        if(s.size()>g.size())
        {
            if(s.top()>x)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else g.push(x);
            cout<<(((int)s.top()+g.top())/2)<<" ";
        }
        else
        {
            if(x<=s.top())
                s.push(x);
            else
            {
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            cout<<s.top()<<" ";
        }
        
    }
    
}