#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) 
{
    vector<string> seen;
    string temp = "";
    for(char i : s)
    {
        if(i == ' ')
        {
            if(!temp.empty())
            {
                seen.push_back(temp);
                temp = "";
            }
        }
        else
        {
            temp += i;
        }
    }
    if(!temp.empty()) seen.push_back(temp);
    string res = "";
    for(int i = seen.size()-1;i>=0;i--)
    {
        res += seen[i];
        if(i != 0) res  += ' ';
    }
    return res;
}

string reverseWordsefficient(string s)
{
    reverse(s.begin(), s.end());
    string res = "";
    string temp = "";
    for(char i : s)
    {
        if(i == ' ')
        {
            if(!temp.empty())
            {
                reverse(temp.begin(), temp.end());
                if(!res.empty()) res += ' ';
                res += temp;
                temp.clear();
            }
        }
        else
        {
            temp += i;
        }
    }
    if(!temp.empty())
    {
        reverse(temp.begin(), temp.end());
        if(!res.empty())
        {
            res += ' ';
        }
        res += temp;
    }
    return res;
}

string longestOddNumber(string &num)
{
    int n = num.size();
    int start = 0;
    int end = n - 1;

    while (end >= 0 && ((num[end] - '0') % 2 == 0))
    {
        end--;
    }
    if (end < 0)
        return "";
    while (start <= end && num[start] == '0')
    {
        start++;
    }
    string res = "";
    for (int i = start; i <= end; i++)
    {
        res += num[i];
    }
    return res;
}

bool isIsomorphic(string s, string t)
{
    if(s.length() != t.length()) return false;
    int x = s.length();
    unordered_map<char, char> seen;
    for(int i=0;i<x;i++)
    {
        if(seen.count(s[i]))
        {
            if(seen[s[i]] != t[i])
            {
                return false;
            }
        }
        else
        {
            seen[s[i]] = t[i];
        }
    }
    return true;
}

int main()
{
    // string res = reverseWordsefficient("  the sky is blue  ");
    // cout << res << endl;
    // cout << res.size() << endl;
    string s = "etg", t = "add";
    cout << isIsomorphic(s, t) << endl;
    return 0;
}