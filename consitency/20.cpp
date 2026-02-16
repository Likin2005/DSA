#include<bits/stdc++.h>
using namespace std;

bool is_isotrophic(string s, string t)
{
    //title : paper
    if(s.length() != t.length()) return false;
    unordered_map<char, char>charIndexS, charIndexT;
    int x = s.length();
    for(int i=0;i<x;i++)
    {
        if(charIndexS.find(s[i]) == charIndexS.end())
        {
            charIndexS[s[i]] = i;
        }
        if(charIndexT.find(t[i]) == charIndexT.end())
        {
            charIndexT[t[i]] = i;
        }
        // if(charIndexS.find(s[i]) != charIndexS.end())
        // {
            if(charIndexT[t[i]] != charIndexS[s[i]])
            {
                return false;
            }
        // }
    }
    return true;
}

int longest_substring(string s)
{
    if(s.empty()) return 0;
    unordered_set<char> seen;
    int left = 0, max_len = 0, x = s.length();
    for(int right = 0;right < x;right++)
    {
        while(seen.find(s[right]) != seen.end())
        {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        max_len = max(max_len,right-left+1);
    }
    return max_len;
}

int main()
{
    cout << is_isotrophic("woo", "adq") << endl;
    return 0;
}