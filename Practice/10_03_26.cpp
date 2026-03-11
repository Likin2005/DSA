#include<bits/stdc++.h>
using namespace std;

int longest_substring(string s)
{
    int left = 0, len = 0;
    unordered_set<char> seen;
    for(int right=0;right < s.length();right++)
    {
        while(seen.count(s[right]))
        {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        len = max(len, right-left+1);
    }
    return len;
}

long aVeryBigSum(vector<long> ar) {
    long res;
    for(long i : ar)
    {
        res += i;
    } 
    return res;
}

int main()
{
    cout << longest_substring("pwwkew");
    return 0;
}