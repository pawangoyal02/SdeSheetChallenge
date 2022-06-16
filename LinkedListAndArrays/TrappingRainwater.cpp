#include <bits/stdc++.h> 
long getTrappedWater(long *height, int n){
    // Write your code here.
        long left=0, right=n-1;
        long res=0;
        long leftMax=0, rightMax=0;
        while(left<=right) {
            if(height[left]<=height[right]) {
                if(height[left]>=leftMax) {
                    leftMax= height[left];
                } else {
                    res+= leftMax-height[left];
                }
                left++;
            }
            
            else{
                if(height[right]>=rightMax) {
                    rightMax= height[right];
                } else {
                    res+= rightMax-height[right];
                }
                right--;
            }
        }
        return res;
}