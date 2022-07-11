// Problem 1- Allocate Books
#include<bits/stdc++.h>

using namespace std;
//to check if allocation of books among given students is possible.
int isPossible(vector < int > & A, int pages, int students) {
  int cnt = 0;
  int sumAllocated = 0;
  for (int i = 0; i < A.size(); i++) {
    if (sumAllocated + A[i] > pages) {
      cnt++;
      sumAllocated = A[i];
      if (sumAllocated > pages) return false;
    } else {
      sumAllocated += A[i];
    }
  }
  if (cnt < students) return true;
  return false;
}
int books(vector < int > & A, int B) {
  if (B > A.size()) return -1;
  int low = A[0];
  int high = 0;
  //to find minimum value and sum of all pages
  for (int i = 0; i < A.size(); i++) {
    high = high + A[i];
    low = min(low, A[i]);
  }
  //binary search
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (isPossible(A, mid, B)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

// Problem 2 Allocate Chapters (Codestudio)


bool isPossible(int n, int m, vector<int> time, long long int mid)
{
    int day=1;
    long long int reqTime= 0;
    for(int i=0; i<m; i++)
    {
        if(reqTime+time[i]<=mid)
        {
            reqTime+=time[i];
        }
        else
        {
            day++;
            if(day>n || time[i] > mid)
            {
                return false;
            }
            reqTime = time[i];
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long start= 0;
    long long totalTime= 0;
    for(int i=0; i<time.size(); i++)
    {
        totalTime+= time[i];
    }
    long long end= totalTime;
    long long ans= -1;
    while(start<=end)
    {
        long long mid= start+(end-start)/2;
        if(isPossible(n,m,time,mid))
        {
            ans= mid;
            end= mid-1;
        }
        else
        {
            start= mid+1;
        }
    }
    return ans;
}