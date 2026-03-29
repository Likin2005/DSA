#include<bits/stdc++.h>
using namespace std;

int string_to_int(string &s)
{
    bool isDigitStarted = false, is_neg = false;
    int res = 0;
    for(char i : s)
    {
        if(i == ' ')
        {
            if(isDigitStarted)break;
            continue;
        }
        else if(i >= '0' && i <= '9')
        {
            res = res * 10 + (i - '0');
            isDigitStarted = true;
        }
        else if((i == '-' || i == '+') && !isDigitStarted && !is_neg)
        {
            is_neg = (i == '-');
        }
        else
        {
            break;
        }
    }
    if(is_neg) return -1 * res;
    return res;
}

int main()
{
    string s = "+-12";
    cout << string_to_int(s) << endl;
    return 0;
}