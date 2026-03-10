#include<bits/stdc++.h>
#include<string>
using namespace std;

int max_consecutive_ones(vector<int> &num)
{
    if(num.empty()) return 0;
    int count = 0, max_count = 0;
    for(int i=0;i<num.size();i++)
    {
        if(num[i] == 1)
        {
            count++;
            max_count = max(count, max_count);
        }
        else
        {
            count=0;
        }
    }
    return max_count;
}

bool is_palindrome(string s)
{
    if(s.size() < 2) return true;
    int left = 0, right = s.size()-1;
    while(left < right)
    {
        if(s[left] != s[right])
        {
            return false;
        }
        left++, right--;
    }
    return true;
}

string reverse_string(string &s)
{
    if(s.size() < 2) return s;
    int left = 0, right = s.size()-1;

    while(left < right)
    {
        char x = s[left];
        s[left] = s[right];
        s[right] = x;
        left++, right--;
    }
    return s;
}

bool valid_palindrome(string s)
{
    int left = 0, right = s.size()-1;
    while(left < right)
    {
        if(!(isalnum(s[left])))
        {
            left++;
            continue;
        }
        else if(!(isalnum(s[right])))
        {
            right--;
            continue;
        }
        else
        {
            if((tolower(s[left]) != tolower(s[right])))
            {
                return false;
            }
        }
        left++, right--;
    }
    return true;
}

void frequency(string s)
{
    if(s.empty()) return;
    unordered_map<char, int> freq;
    for(char i : s) freq[i]++;
    for(auto i : freq) cout << i.first << " : " << i.second << " ";
}

char first_non_repeating(string s)
{
    map<char, int> seen;
    for(char i : s)seen[i]++;
    for(char i : s)
    {
        if(seen[i] == 1)
        {
            return i;
        }
    }
    return ' ';
}

string remove_duplicate(string s)
{
    if(s.size() < 2) return s;
    string res;
    vector<bool> seen(256, false);
    for(unsigned char i : s)
    {
        if(!(seen[i]))
        {
            res+=i;
            seen[i] = true;
        }
    }
    return res;
}

string toggle_case(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(islower(s[i])) s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
    }
    return s;
}

int main()
{
    string s = "programming";
    cout << remove_duplicate(s) << endl;
    return 0;
}