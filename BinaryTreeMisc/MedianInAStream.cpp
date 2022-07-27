#include<bits/stdc++.h>
void balanceHeaps(priority_queue<int> &max_heap, priority_queue<int, vector<int>, greater<int>> &min_heap)
{
    if(max_heap.size()-min_heap.size()==2)
    {
        min_heap.push(max_heap.top());
        max_heap.pop();
    }
    else if(min_heap.size() - max_heap.size() == 1)
    {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
}
void addNum(int num, priority_queue<int> &max_heap, priority_queue<int, vector<int>, greater<int>> &min_heap)
{
    if(max_heap.empty() || num <= max_heap.top())
            max_heap.push(num);
        else
            min_heap.push(num);
        balanceHeaps(max_heap, min_heap);
}
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
    priority_queue<int> max_heap; // stores the smaller half
        priority_queue<int, vector<int>, greater<int>> min_heap; // stores the larger half    
        vector<int> res;
    for(int i=0; i<n; i++)
    {
        addNum(arr[i], max_heap, min_heap);
        if(max_heap.size()==min_heap.size())
        {
            res.push_back((max_heap.top()+min_heap.top())/2);
        }
        else
        {
            res.push_back(max_heap.top());
        }
    }
    return res;
}
