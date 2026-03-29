#include<bits/stdc++.h>
using namespace std;

string remove_parenthesis(string &s)
{
    string res = "";
    int counter = 0;
    for(char i : s)
    {
        if(i == '(')
        {
            counter++;
            if(counter > 1)
            {
                res += '(';
            }
        }
        else
        {
            counter--;
            if(counter)
            {
                res += ')';
            }
        }
    }
    return res;
}

int count_substring(string &s, int k)
{
    map<char, int> seen;
    int count = 0,left = 0;
    for(int right = 0;right < s.length();right++)
    {
        seen[s[right]]++;
        while(seen.size() > k)
        {
            seen[s[left]]--;
            if(seen[s[left]] == 0)seen.erase(s[left]);
            left++;
        }
        count += (right - left + 1);
    }
    return count;
}

int helper(string s, int k)
{
    return count_substring(s, k) - count_substring(s, k-1);
}

int main()
{
    string x = "pqpqs";
    cout << helper(x, 2) << endl;
    return 0;
}