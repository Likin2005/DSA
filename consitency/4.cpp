#include<bits/stdc++.h>
using namespace std;

int majority_element(vector<int> &n)
{
    int ans = 0, freq = 0;
    for(int i : n)
    {
        if(freq == 0)
        {
            ans = i;
        }
        if(ans == i)
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    int cnt = 0;
    for(int i : n)
    {
        if(i == ans)
        {
            cnt++;
        }
    }
    if(cnt > n.size()/2) return ans;
    return -1;
}

int maximum_sum(vector<int> &n)
{
    int sum = 0, max_sum = 0, x = n.size();
    // for(int i=0;i<x;i++)
    // {
    //     sum = 0;
    //     for(int j=i;j<x;j++)
    //     {
    //         sum += n[j];
    //         max_sum = max(sum,max_sum);
    //     }
    // }
    // return max_sum;

    for(int i : n)
    {
        sum += i;
        max_sum = max(sum,max_sum);
        if(sum < 0)
        {
            sum = 0;
        }
    }
    return max_sum;
}

int buy_sell_stock(vector<int> &n)
{
    int profit = 0, x = n.size(), buy = n[0], cost;
    for(int i=1;i<x;i++)
    {
        cost = n[i] - buy;
        profit = max(profit, cost);
        buy = min(buy, n[i]);
    }
    return profit;
}

vector<int> sort_by_sign(vector<int> &n)
{
    int pos_ind = 0,neg_ind = 1,x = n.size();
    vector<int> res(x);
    for(int i=0;i<x;i++)
    {
        if(n[i] > 0)
        {
            res[pos_ind] = n[i];
            pos_ind+=2;
        }
        else
        {
            res[neg_ind] = n[i];
            neg_ind+=2;
        }
    }
    return res;
}



int main()
{
    vector<int> r = {3,1,-8,-5,4,6,-4,-7};
    vector<int> res = sort_by_sign(r);
    for(int i : res)
    {
        cout << i << " ";
    }
    return 0;
}