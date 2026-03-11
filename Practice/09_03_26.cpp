#include<bits/stdc++.h>
using namespace std;

bool valid_anagrams(string &s, string &t)
{
    if(s.length() != t.length()) return false;
    unordered_map<char, int> seen;

    for(char i : s)seen[i]++;
    for(char i : t)seen[i]--;
    for(auto it : seen) if(it.second != 0) return false;
    return true;
}

vector<vector<string>> group_anagrams(vector<string> &str)
{
    if(str.empty()) return {{}};
    unordered_map<string, vector<string>> seen;
    for(string i : str)
    {
        string res = i;
        sort(i.begin(), i.end());
        seen[i].push_back(res);
    }
    vector<vector<string>> res;
    for(auto it : seen)
    {
        res.push_back(it.second);
    }
    return res;
}

int first_non_repeating(string s)
{
    if(s.empty()) return -1;
    unordered_map<char, int> seen;
    for(char i : s) seen[i]++;
    for(int i=0;i<s.size();i++) if(seen[s[i]] == 1) return i;
    return -1;
}

bool isomorphic(string s, string t)
{
    if(s.length() != t.length()) return false;
    unordered_map<char, char> seen1, seen2;
    for(int i=0;i<s.length();i++)
    {
        if(seen1.find(s[i]) == seen1.end() && seen2.find(t[i]) == seen2.end())
        {
            seen1[s[i]] = t[i];
            seen2[t[i]] = s[i];
        }
        else
        {
            if(seen1[s[i]] != t[i])
            {
                return false;
            }
        }
    }
    return true;
}

int longestPalindrome(string s)
{
    if(s.empty()) return 0;
    if(s.size() == 1) return 1;
    unordered_map<char, int> seen;
    int count = 0;
    bool flag = false;

    for(char i : s) seen[i]++;
    for(auto it : seen)
    {
        if(it.second % 2 == 0) count += it.second;
        if(it.second % 2 != 0) count += (it.second - 1); flag = true;
    }
    if(flag) return count+1;
    return count;
    ;
}

int main()
{
    string s = "abccccdd";
    cout << isomorphic("aabaa", "xxzyy") << endl;
    return 0;
}