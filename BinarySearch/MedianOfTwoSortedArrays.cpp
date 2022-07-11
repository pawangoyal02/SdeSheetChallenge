// Naive Approach Sol

int n= nums1.size();
        int m= nums2.size();
        vector<int> finalArray(n+m);
        int i=0, j=0, k=0;
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            {
                finalArray[k++]= nums1[i++];
            }
            else
            {
                finalArray[k++]= nums2[j++];
            }
        }
        
        if(i<n)
        {
            while(i<n)
            {
                finalArray[k++]= nums1[i++];
            }
        }
        
        if(j<m)
        {
            while(j<m)
            {
                finalArray[k++]= nums2[j++];
            }
        }
        
        n= n+m;
        if(n%2==1) return (double)finalArray[((n+1)/2)-1];
        else return ((double)finalArray[(n/2)-1] + (double)finalArray[(n/2)])/2;

        // Binary Search Sol

        class Solution {
public:
    // Binary Search Solution
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        if(n>m) return findMedianSortedArrays(nums2, nums1);
        int low= 0, high= n, medianPos= (n+m+1)/2;
        while(low<=high)
        {
            int cut1= (low+high)/2;
            int cut2= medianPos-cut1;
            
            int l1= cut1==0 ? INT_MIN : nums1[cut1-1];
            int l2= cut2==0 ? INT_MIN : nums2[cut2-1];
            int r1= cut1==n ? INT_MAX : nums1[cut1];
            int r2= cut2==m ? INT_MAX : nums2[cut2];
            
            if(l1<=r2 && l2<=r1)
            {
                if((m+n)%2==0)
                {
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }
                else
                    return max(l1,l2);
            }
            
            if(l1>r2) high= cut1-1;
            else low= cut1+1;
        }
        return 0.0;
    }
};