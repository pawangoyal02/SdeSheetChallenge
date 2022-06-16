#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & matrix, int m, int n, int target) {
    // Write your code here.
    int lo = 0;
        if(!m) return false;
        int hi = (m * n) - 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/n][mid % n] == target) {
                return true;
            }
            if(matrix[mid/n][mid % n] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
}