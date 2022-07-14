// Solution 1- Brute Force O(N^2)
#include<bits/stdc++.h>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea= 0;
        int n= heights.size();
        for(int i=0; i<n; i++)
        {
            int minHeight= INT_MAX;
            for(int j=i; j<n; j++)
            {
                minHeight= min(minHeight,heights[j]);
                maxArea= max(maxArea, minHeight*(j-i+1));
            }
        }
        return maxArea;
    }
};

// Solution 2 Optimised Approach 1

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
        }
        if (st.empty())
          leftsmall[i] = 0;
        else
          leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
    }
};

// Solution 3- Optimised Approach 2 (Most Optimal)

class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        stack < int > st;
      int maxA = 0;
      int n = histo.size();
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
};