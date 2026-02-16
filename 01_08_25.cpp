#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int odd_occurence(vector<int>& nums)
{
    int odd=0;
    for(int i : nums)
    {
        odd^=i;
    }
    return odd;
}

int odd_times(vector<int>& nums)
{
    unordered_map<int,int> map;
    for(int i : nums)
    {
        map[i]++;
    }
    for(int i : nums)
    {
        if(map[i] % 2 != 0)
        {
            return i;
        }
    }
}

vector<vector<string>> sort_anagrams(vector<string>& nums)
{
    unordered_map<string,vector<string>> map;
    for(string str : nums)
    {
        string key = str;
        sort(str.begin(),str.end());
        map[str].push_back(key);
    }
    vector<vector<string>> group;
    for(auto it : map)
    {
        vector<string> x = it.second;
        group.push_back(x);
    }
    return group;
}

int main()
{
    vector<string> nums = {"cat","bat","ate","tea","tac","eat"};
    vector<vector<string>> res = sort_anagrams(nums);
    for(vector<string> str : res)
    {
        for(string s : str)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}