// Approach 1 Brute Force O(N^2)

#include<bits/stdc++.h>
bool check(vector<int> positions, int n, int dist, int c)
{
    int k= positions[0];
    c--;
    for(int i=1; i<n; i++)
    {
        if(positions[i]-k >= dist)
        {
            c--;
            if(!c) return true;
            k= positions[i];
        } 
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(), positions.end());
    int maxD= positions[n-1]-positions[0];
    int ans= INT_MIN;
    for(int i=1; i<=maxD; i++)
    {
        if(check(positions,n,i,c))
        {
            ans= max(ans,i);
        }
    }
    return ans;
}

// Binary Search Approach

bool check(vector<int> positions, int n, int dist, int c)
{
    int k= positions[0];
    c--;
    for(int i=1; i<n; i++)
    {
        if(positions[i]-k >= dist)
        {
            c--;
            if(!c) return true;
            k= positions[i];
        } 
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(), positions.end());
    int low=1;
    int high= positions[n-1]-positions[0];
    int ans= INT_MIN;
    //binary search
    while(low<=high)
    {
        int mid= (low+high)>>1;
        if(check(positions,n,mid,c))
        {
            ans= mid;
            low= mid+1;
        }
        else
        {
            high= mid-1;
        }
    }
    return ans;
}