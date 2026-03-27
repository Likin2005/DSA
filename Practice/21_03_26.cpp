#include<bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(string s) 
{
    map<char, int> seen;
    for(char i : s) seen[s[i]]++;
    int freq = -1;
    char res = 'z';
    for(auto it : seen)
    {
        if(it.second > freq && it.first < res)
        {
            res = it.first;
        }
    }
    return res;
}

int main()
{
    string res = "testcases";
    cout << getMaxOccuringChar(res);
    return 0;
}