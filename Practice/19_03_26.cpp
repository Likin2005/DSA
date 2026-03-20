#include<bits/stdc++.h>
using namespace std;

bool areRotations(string &s1, string &s2)
{
    s1 = s1+s1;
    int pos = s1.find(s2);
    if(pos != -1) return true;
    return false;
}

bool as_leading_zero(string s)
{
    return (s.length() > 1 && s[0] == '0');
}

bool IPV4_Validation(string s)
{
    int count = 0;
    string temp = "";
    for(char i : s)
    {
        if(i == '.')
        {
            if(!temp.empty())
            {
                int n = stoi(temp);
                if(as_leading_zero(temp)) return false;
                if(n > 255 || n < 0) return false;
                temp.clear();
                count++;
            }
            else
            {
                return false;
            }
        }
        else
        {
            temp += i;
        }
    }
    if(!temp.empty())
    {
        int n = stoi(temp);
        if(as_leading_zero(temp)) return false;
        if(n > 255 || n < 0) return false;
        temp.clear();
        count++;
    }
    return (count == 4);
}

long long string_int(string s)
{
    bool digitStarted = false;
    long long res = 0;
    for(char i : s)
    {
        if(i == '-') continue;
        if(i == '0' && !digitStarted)
        {
            continue;
        }
        else
        {
            digitStarted = true;
            res = res * 10 + (i - '0');
        }
    }
    return res;
}

string multiplyStrings(string s1, string s2) 
{
    bool is_neg1 = false, is_neg2 = false;
    if(s1[0] == '-')is_neg1 = true;
    if(s2[0] == '-')is_neg2 = true;

    if((is_neg1 && is_neg2) || (!is_neg1 && !is_neg2)) return to_string((long long)string_int(s1) * (long long)string_int(s2));
    else if(is_neg1 || is_neg2) return to_string(-1 * (long long)string_int(s1) * (long long)string_int(s2));
}

int main()
{
    cout << multiplyStrings("4989", "405");
    return 0;
}