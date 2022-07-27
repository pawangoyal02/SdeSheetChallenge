class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0, j=0;
        while(i<v1.length() || j<v2.length())
        {
            int x=0;
            int y=0;
            
            while(i<v1.length() && v1[i]!='.')
            {
                x= x*10 + (v1[i]-'0');
                i++;
            }
            
            while(j<v2.length() && v2[j]!='.')
            {
                y = y*10 + (v2[j]-'0');
                j++; 
            }
            
            i++;
            j++;
            
            if(x<y) return -1 ; 
            else if(x>y) return 1 ;
        }
        return 0;
    }
};