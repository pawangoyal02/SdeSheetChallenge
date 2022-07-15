class Solution 
{
    public:
    bool knows(vector<vector<int> >& M, int a, int b)
    {
        if(M[a][b]==1) return true;
        else return false;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        //step1: Push all the elements in the stack
        for(int i=0; i<n; i++)
        {
            st.push(i);
        }
        
        // Step2: Get 2 elements and compare them
        
        while(st.size()>1)
        {
            int a= st.top();
            st.pop();
            
            int b= st.top();
            st.pop();
            
            if(knows(M,a,b))
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        int ans= st.top();
        // Step3: Single element in the stack is the potential celebrity
        // so verify it
        
        int zeroCount= 0;
        
        for(int i=0; i<n; i++)
        {
            if(M[ans][i]==0)
            {
                zeroCount++;
            }
        }
        
        if(zeroCount != n)
        {
            return -1;
        }
    
        int oneCount= 0;
        
        for(int i=0; i<n; i++)
        {
            if(M[i][ans]==1)
            {
                oneCount++;
            }
        }
        
        if(oneCount != n-1)
        {
            return -1;
        }
        
        return ans;
    }
};