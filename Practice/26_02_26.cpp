#include<bits/stdc++.h>
using namespace std;

int kadanes_algo(vector<int> &num)
{
    if(num.empty()) return 0;
    int sum = num[0], max_sum = num[0];

    for(int i=1;i<num.size();i++)
    {
        sum = max(num[i], sum+num[i]);
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

int binary_to_decimal(string s)
{
    if(s.empty()) return 0;
    int n = 0, x = s.size()-1;

    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '1')
        {
            n += pow(2, x);
        }
        x--;
    }
    return n;
}

int main()
{
    vector<int> r = {2, -2, 0, 3, -3, 5};
    // vector<vector<int>> res = three_sum(r);
    // for(vector<int> i : res)
    // {
    //     for(int j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    cout << binary_to_decimal("1101") << endl;
    return 0;
}