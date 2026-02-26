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

vector<vector<int>> three_sum(vector<int> &num)
{
    if(num.size() < 3) return {{}};
    vector<vector<int>> res;
    
    for(int i=0;i<num.size();i++)
    {
        for(int j=i+1;j<num.size();j++)
        {
            for(int k=j+1;k<num.size();k++)
            {
                if(num[i] != num[j] && num[j] != num[k] && num[k] != num[i])
                {
                    if(num[i] + num[j] + num[k] == 0)
                    {
                        res.push_back({num[i], num[j], num[k]});
                    }
                }
            }
        }
    }
    return res;
}

int binary_to_decimal(string s)
{
    if(s.empty()) return 0;
    int n = 0, x = s.size()-1;

    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '1')
        {
            n += (1 << x);
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