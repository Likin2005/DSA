#include<bits/stdc++.h>
using namespace std;

int longest_k_substring(string s, int k)
{
    if(s.empty()) return 0;
    int left = 0,len = 0;
    map<char, int> seen;

    for(int right = 0;right < s.size();right++)
    {
        seen[s[right]]++;

        while(seen.size() > k)
        {
            seen[s[left]]--;

            if(seen[s[left]] == 0) seen.erase(s[left]);
            left++;
        }

        len = max(len, right-left+1);
    }

    return len;
}

int main()
{
    string x = "abababc";
    cout << char(65) << endl;
    return 0;
}