#include<bits/stdc++.h>
using namespace std;

int longestContinuousString(string s)
{
    if(s.empty()) return 0;
    if(s.size() == 1) return 1;
    int count = 0;

    for(int i=0;i<s.size();i++)
    {
        char item = s[i];
        while(s.find(item + 1))
        {
            item = s[i+1];
            count++;
        }
    }
}

int main()
{
    char x = 'a';
    cout << char(x+1);
    return 0;
}