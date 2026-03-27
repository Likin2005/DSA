#include<bits/stdc++.h>
using namespace std;

int roman_to_int(string s)
{
    map<char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    int index = 0,res = 0;
    while(index < s.size())
    {
        if(roman[s[index+1]] > roman[s[index]])
        {
            res += (roman[s[index+1]] - roman[s[index]]);
            index += 2;
        }
        else
        {
            res += roman[s[index]];
            index++;
        }
    }
    return res;
}

int substring_k_unique(string s, int k)
{
    unordered_map<char, int> seen;
    int left = 0, count = 0;

    for(int right = 0; right < s.size(); right++)
    {
        seen[s[right]]++;

        while(seen.size() > k)
        {
            seen[s[left]]--;
            if(seen[s[left]] == 0) seen.erase(s[left]);
            left++;
        }

        count += right - left + 1;
    }
    return count;
}

int at_most(string s, int k)
{
    // Exactly k distinct = atMost(k) - atMost(k-1)
    return substring_k_unique(s, k) - substring_k_unique(s, k - 1);
}

bool is_boolean(string s)
{
    for(char i : s)
    {
        if((i != '0')&&(i != '1')) return false;
    }
    return true;
}

string uniques(string s)
{
    map<char, int> seen;
    for(char i : s) seen[i]++;
    string res = "";
    for(auto it : seen)
    {
        res += it.first;
    }
    return res;
}

string first_repeating(string s)
{
    unordered_map<char, int> seen;
    for(char i : s) seen[i]++;
    for(char i : s)
    {
        if(seen[i] > 1)
        {
            return to_string(i);
        }
    }
    return "-1";
}

int main()
{
    cout << first_repeating("avvb");
    return 0;
}