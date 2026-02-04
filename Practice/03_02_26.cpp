#include<bits/stdc++.h>
using namespace std;

string reverseVowels(string &s)
{
    if(s.empty()) return "";
    vector<bool> track(128, false);
    string vowels = "aeiouAEIOU";

    for(char i : vowels)
    {
        track[i] = true;
    }

    int left = 0, right = s.length()-1;
    while(left < right)
    {
        if(! track[s[left]])
        {
            left++;
        }
        else if(! track[s[right]])
        {
            right--;
        }
        else
        {
            swap(s[right], s[left]);
            right--, left++;
        }
    }
    return s;
}



string reverseit(string s, int k)
{
    string result = s;
    string rev = s;
    reverse(rev.begin(), rev.end());

    for (int i = 1; i <= k; i++)
    {
        if (i % 2 == 0)
            s += result;   // even → reversed
        else
            s += rev;     // odd → original
    }

    return s;
}

int main()
{
    string s = "has";
    cout << reverseit(s, 5) << endl;
    return 0;
}