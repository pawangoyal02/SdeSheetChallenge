// No Circular Array

#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> nge(n,-1);
    stack<int> st;
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        if(!st.empty()) nge[i]= st.top();
        st.push(arr[i]);
    }
    return nge;
}

// Leetcode No Circular Array

class Solution {
public:
    void nextGreater(vector<int> &arr, int n, vector<int> &nge) {
    // Write your code here
    stack<int> st;
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        if(!st.empty()) nge[i]= st.top();
        st.push(arr[i]);
    }
}
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n1= nums1.size();
        int n2= nums2.size();
        vector<int> nge(n2,-1);
        nextGreater(nums2,n2,nge);
        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<n2; j++)
            {
                if(nums1[i]==nums2[j])
                {
                    ans.push_back(nge[j]);
                }
            }
        }
        return ans;
    }
};

// Circular Array Leetcode

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
    }
};

