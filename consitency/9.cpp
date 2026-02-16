#include<bits/stdc++.h>
using namespace std;

bool valid_palindrome(string &s)
{
    int st = 0, end = s.length()-1;
    while(st <= end)
    {
        if(!isalnum(s[st]))
        {
            st++;continue;
        }
        else if(!isalnum(s[end]))
        {
            end--;continue;
        }
        else if(towlower(s[st]) != tolower(s[end]))
        {
            return false;
        }
        st++,end--;
    }
    return true;
}

int main()
{
    string s = "daabcbaabcabc", sub = "abc";
    while(s.find(sub) < s.length())
    {
        s.erase(s.find(sub),s.find(sub)+sub.length());
    }
    cout << s << endl;
    return 0;
}