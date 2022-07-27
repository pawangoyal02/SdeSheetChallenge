int minCharsforPalindrome(string str) {
	// Write your code here.
	int l=0, r=0;
    int ans;
    bool flag= true;
    for(int i=str.length()-1; i>=0; i--)
    {
        l= 0;
        r= i;
        flag= true;
        while(l<r)
        {
            if(str[l]==str[r])
            {
                l++;
                r--;
            }
            else
            {
                flag= false;
                break;
            }
        }
        if(flag)
        {
            r= i;
            break;
        }
    }
    ans= str.length()-r-1;
    return ans;
}
