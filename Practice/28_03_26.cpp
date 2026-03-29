#include<bits/stdc++.h>
using namespace std;

int string_to_int(string &s)
{
    bool isDigitStarted = false, is_neg = false, sign_used = false, exceed = false;
    int res = 0;
    for(char i : s)
    {
        if(i == ' ')
        {
            if(isDigitStarted || sign_used)break;
            continue;
        }
        else if(i >= '0' && i <= '9')
        {
            long long temp = (long long) res * 10 + (i - '0');
            if(temp > INT_MAX)
            {
                exceed = true;
                break;
            }
            else
            {
                res = temp;
            }
            isDigitStarted = true;
        }
        else if((i == '-' || i == '+') && !isDigitStarted && !sign_used)
        {
            is_neg = (i == '-');
        }
        else
        {
            break;
        }
    }
    if(exceed && is_neg) return -1 * INT_MAX - 1;
    if(exceed && !is_neg)return INT_MAX;
    if(!exceed && is_neg) return -1 * res; 
    return res;
}

int main()
{
    string s = "+-12";
    cout << string_to_int(s) << endl;
    return 0;
}