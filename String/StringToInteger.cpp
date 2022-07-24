// Leetcode

class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int i=0, len = str.length();
        bool neg = false;

        while(str[i]==' ') i++;
        if(str[i]=='+') i++;
        else if(str[i]=='-') {i++; neg=true;}

        while(str[i]>='0' && str[i]<='9'){
            res = res*10 + str[i]-'0';
            if(res>=INT_MAX && !neg) {res = INT_MAX; break;}
            else if(res>INT_MAX && neg) {res = INT_MIN; break;}
            i++;
        }

        if (neg) res *= -1;
        return (int)res; 
    }
};

// Codestudio

int atoi(string str) {
    int sign=1;
    int i=0;
    int ans=0;
    if(str[i]=='-'){
        sign=-1;
        i++;
    }
    for(;i<str.length();i++){
        if(str[i]-'0'>=0 && str[i]-'0'<=9){
            ans=ans*10+str[i]-'0';
        }
    }
    return ans*sign;
}