#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n= start.size();
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++) {
        v[i].first= finish[i];
        v[i].second= start[i];
    }
    sort(v.begin(), v.end());
    int c=0, temp=0;
    
    for(int i=0; i<n; i++) {
        if(i==0) {
            c++;
            temp= v[i].first;
        }
        else {
            if(v[i].second>=temp) {
                c++;
                temp= v[i].first;
            }
        }
    }
    return c;
}