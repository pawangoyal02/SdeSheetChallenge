// Codestudio

#include<bits/stdc++.h>
bool dictionaryContains(string &word, vector<string> &dictionary)
{
    for(int i=0; i<dictionary.size(); i++)
    {
        if(dictionary[i].compare(word)==0)
            return true;
    }
    return false;
}
void wordBreakUtil(string s, int n,string result, vector<string> &dictionary, vector<string> &ans)
{
    for(int i=1; i<=n; i++)
    {
        string prefix= s.substr(0,i);
        
        if(dictionaryContains(prefix, dictionary))
        {
            if(i==n)
            {
                result+=prefix;
                ans.push_back(result);
                return;
            }
            wordBreakUtil(s.substr(i,n-i),n-i,result+prefix+" ",dictionary,ans);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    int n= s.size();
    vector<string> ans;
    wordBreakUtil(s,n,"",dictionary,ans);
    return ans;
}

// leetcode

class Solution {
public:
    set<string> dict;
    unordered_map<string,bool> memo;
    int n;
    bool check(string &s)
    {
        if(s.size()==0)
        {
            return true;
        }
        for(int j=1;j<=s.length();j++)
        {
            string left=s.substr(0,j);
            string right=s.substr(j);
            if(memo.find(s)!=memo.end())
            return memo[s];
            if(dict.find(left)!=dict.end()&&check(right))
            {
                return memo[s]=true;
            }
        }
        return memo[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        for(auto &word:wordDict)
        {
            dict.insert(word);
        }
        return check(s);
    }
};