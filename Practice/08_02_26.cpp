#include<bits/stdc++.h>
using namespace std;

int kadane_algorithm(vector<int> &num)
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

int max_subarray_product(vector<int>& num)
{
    if(num.empty()) return 0;
    int global = num[0], max_prod = num[0], min_prod = num[0];
    for(int i=1;i<num.size();i++)
    {
        int curr = num[i];
        if(curr < 0)
        {
            swap(max_prod, min_prod);
        }

        max_prod = max(curr, max_prod*curr);
        min_prod = min(curr, min_prod*curr);
        global = max(global, max_prod);
    }
    return global;
}

int buying_stocks(vector<int> &num)
{
    if(num.empty()) return 0;
    int buy = num[0],sell, max_profit = 0;
    for(int i=1;i<num.size();i++)
    {
        max_profit = max(max_profit, num[i] - buy);
        buy = min(buy, num[i]);
    }
    return max_profit;
}

int main()
{
    vector<int> num = {7,1,5,3,6,4};
    cout << buying_stocks(num) << endl;
    return 0;
}