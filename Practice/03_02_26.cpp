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

int main()
{
    string s = "IcecReAm";
    cout << reverseVowels(s) << endl;
    return 0;
}