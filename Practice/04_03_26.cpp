#include<bits/stdc++.h>
using namespace std;

string longest_common_prefix(vector<string>& strs)
{
    sort(strs.begin(), strs.end());
    string res;
    for(int i=0;i<min(strs[0].size(),strs[strs.size()-1].size());i++)
    {
        if(strs[0][i] == strs[strs.size()-1][i])
        {
            res += strs[0][i];
        }
        else break;
    }
    return res;
}

bool valid_anagrams(string s, string t)
{
    if(s.length() != t.length()) return false;
    unordered_map<char, int> seen;
    for(char i : s) seen[i]++;
    for(char i : t) seen[i]--;
    for(auto it : seen) if(it.second != 0) return false;
    return true;
}

vector<map<string, string>> group_anagrams(vector<string> &str)
{
    
}

int main()
{
    cout << valid_anagrams("silent", "lisen");
    return 0;
}