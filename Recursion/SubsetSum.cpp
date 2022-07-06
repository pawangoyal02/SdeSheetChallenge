void func(int ind, int sum, vector<int> &arr, int N, vector<int> &SubsetSums)
    {
        if(ind==N)
        {
            SubsetSums.push_back(sum);
            return;
        }
        func(ind+1, sum+arr[ind], arr, N, SubsetSums);
        func(ind+1, sum, arr, N, SubsetSums);
    }
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
        int N= num.size();
        vector<int> SubsetSums;
        func(0,0,num,N,SubsetSums);
        sort(SubsetSums.begin(),SubsetSums.end());
        return SubsetSums;
}