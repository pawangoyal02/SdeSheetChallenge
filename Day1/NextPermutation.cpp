#include <bits/stdc++.h> 
void swap(int &a, int &b)
    {
        int temp= a;
        a=b;
        b=temp;
    }
vector<int> nextPermutation(vector<int> &nums, int n)
{
    //  Write your code here.
    int k, l;
        for(k=n-2; k>=0; k--)
        {
            if(nums[k]<nums[k+1])
            {
                break;
            }
        }
        if(k<0)
        {
            reverse(nums.begin(), nums.end());
        }
        else{
            for(l=n-1; l>=0; l--)
            {
                if(nums[l]>nums[k])
                {
                    break;
                }
            }
        swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());
        }
    return nums;
}