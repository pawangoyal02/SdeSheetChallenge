// Method 1

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        return false;
    }
};

// Method 2

class Solution {
public:
    bool isAnagram(string s, string t) {
    int n=s.length();
    int m=t.length();
    if(m!=n) return false;
    unordered_map<char, int> mp;
    for(int i=0; i<n; i++)
    {
        mp[s[i]]++;
    }
    for(int i=0; i<n; i++)
    {
        if(mp[t[i]]==0)
        {
            return false;
        }
        mp[t[i]]--;
    }
    return true;
    }
};

