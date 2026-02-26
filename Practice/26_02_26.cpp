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

int main()
{
    vector<int> r = {-2, -3, -7, -2, -10, -4};
    cout << kadanes_algo(r) << endl;
    return 0;
}