#include<bits/stdc++.h>
using namespace std;

int binary_decimal(string s)
{
    int res = 0, p = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[s.size() - i - 1] == '1')
        {
            res += (1 << i);
        }
    }
    return res;
}

string decimal_binary(int n)
{
    string res = "";
    while(n != 0)
    {
        int temp = n % 2;
        n = n / 2;
        res.push_back(temp + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    // string s = "11101";
    // cout << binary_decimal(s);
    cout << decimal_binary(29);
    return 0;
}