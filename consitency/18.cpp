#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal)
{
    int x = s.length();
    for(int i=0;i<x;i++)
    {
        if(s == goal)
        {
            return true;
        }
        else
        {
            char a = s[0];
            for(int j=1;j<x;j++)
            {
                s[j-1] = s[j];
            }
            s[x-1] = a;
        }
    }
    return false;
}

bool rotating(string x, string y)
{
    string res = x + x;
    int m = res.length(), n = y.length();
    for(int i=0;i<=m-n;i++)
    {
        if(res.substr(i,n) == y)
        {
            return true;
        }
    }
    return false;
}

bool valid_anagrams(string a, string b)
{
    if(a.length() != b.length()) return false;
    unordered_map<char,int> seen;
    for(int i=0;i<a.length();i++)
    {
        seen[a[i]]++,seen[b[i]]--;
    }
    for(char i : a)
    {
        if(seen[i] != 0)
        {
            return false;
        }
    }
    return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> seen;
    vector<vector<string>> res;
    for(string i : strs)
    {
        string item = i;
        sort(i.begin(), i.end());
        seen[i].push_back(item);
    }
    for(auto it : seen)
    {
        res.push_back(it.second);
    }
    return res;
}

vector<vector<int>> two_sum(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int right = 0, left = nums.size()-1;
    while(right < left)
    {
        if(abs(nums[right]) > abs(nums[left]))
        {
            right++;
        }
        else if (abs(nums[right]) < abs(nums[left]))
        {
            left--;
        }
        else
        {
            res.push_back({nums[right], nums[left]});
            right++, left--;
        }
    }
    return res;
}

int main()
{
    // string x = "abcde", y = "bcdea";
    // cout << valid_anagrams(x,y) << endl;
    // vector<string> a = {"eat","tea","tan","ate","nat","bat"};
    // vector<vector<string>> res = groupAnagrams(a);
    // for(vector<string> i : res)
    // {
    //     for(string j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    vector<int> r = {7,5,3,1,-5,-1,2,0}; // {-3,-2,-1,0,0,1,1,2}
    vector<vector<int>> res = two_sum(r);
    for(vector<int> i : res)
    {
        for(int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}