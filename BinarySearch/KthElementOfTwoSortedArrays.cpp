// Sol 1

int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int p1=0, p2=0, c=0, ans=0;
        
        while(p1<n && p2<m)
        {
            if(c==k) break;
            
            else if(arr1[p1]<arr2[p2])
            {
                ans= arr1[p1];
                p1++;
            }
            else
            {
                ans= arr2[p2];
                p2++;
            }
            c++;
        }
        if(c!=k)
        {
            if(p1!=n-1) ans= arr1[k-c];
            else ans= arr2[k-c];
        }
        return ans;
    }

    // Binary Search Sol

    class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m<n){
            return kthElement(arr2,arr1,m,n,k);
        }
        
        int low=max(0,k-m);
        int high=min(k,n);
        
        while(low<=high){
        int p1=(low+high)/2;
        int p2=k-p1;
        
        int l1=p1==0 ? INT_MIN : arr1[p1-1];
        int l2=p2==0 ? INT_MIN : arr2[p2-1];
        int r1=p1==n ? INT_MAX : arr1[p1];
        int r2=p2==m ? INT_MAX : arr2[p2];
        
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            high=p1-1;
        }
        else{
            low=p1+1;
        }
        }
        return 1;
    }
};