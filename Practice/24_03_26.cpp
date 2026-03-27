#include<bits/stdc++.h>
using namespace std;

int longest_array_with_zero(vector<int> &num)
{
    if(num.size() == 0)return 0;
    unordered_map<int, int> seen;
    int len = 0, sum = 0;

    for(int i=0;i<num.size();i++)
    {
        sum += num[i];

        if(sum == 0) len = i + 1;

        if(seen.find(sum) != seen.end())
        {
            len = max(len, i - seen[sum]);
        }

        if(seen.find(sum) == seen.end())
        {
            seen[sum] = i;
        }
    }
    return len;
}

bool is_isomorphic(string s, string t)
{
    if(s.size() != t,size()) return false;
    map<char, char>x, y;
    for(int i=0;i<x.size();i++)
    {
        if(x.find(s[i]) )
    }
}

int main()
{
    vector<int> seen = {15, -2, 2, -8, 1, 7, 10, 23}, x = {2, 10, 4};
    cout << longest_array_with_zero(x);
    return 0;
}