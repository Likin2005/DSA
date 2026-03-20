#include<bits/stdc++.h>
using namespace std;

string reverseWords(string &s) 
{
    string res = "", temp = "";
    reverse(s.begin(), s.end());
    for(char i : s)
    {
        if(i == '.')
        {
            if(temp.empty()) 
            {
                continue;
            }
            else
            {
                reverse(temp.begin(), temp.end());
                if(!res.empty()) res+='.';
                res+=temp;
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
        if(!res.empty()) res+='.';
        res+=temp;
    }
    return res;
}

int main()
{  
    string s = "..geeks..for.geeks.";
    cout << reverseWords(s);
    return 0;
}