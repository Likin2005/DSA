#include<bits/stdc++.h>
using namespace std;

int kadane_s_algo(vector<int> &num)
{
    if(num.size() == 0) return 0;
    int sum = num[0], max_sum = num[0];
    for(int i=1;i<num.size();i++)
    {
        sum = max(num[i], sum+num[i]);
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}

int max_product(vector<int> &n)
{
    if(n.empty()) return 0;
    int global = n[0], max_p = n[0], min_p = n[0];

    for(int i=1;i<n.size();i++)
    {
        int curr = n[i];

        if(curr < 0) swap(max_p, min_p);

        max_p = max(curr, max_p * curr);
        min_p = min(curr, min_p * curr);
        global = max(global, max_p);
    }
    return global;
}

vector<int> self_product(vector<int> &num)
{
    vector<int> left(num.size()), right(num.size()), res(num.size());
    left[0] = 1, right[num.size()-1] = 1;
    int l_prod = 1, r_prod = 1;
    for(int i=1;i<num.size();i++)
    {
        l_prod = l_prod * num[i-1];
        left[i] = l_prod;
        r_prod = r_prod * num[num.size() - i];
        right[num.size()-i-1] = r_prod;
    }
    for(int i=0;i<num.size();i++)
    {
        res[i] = right[i] * left[i];
    }
    return res;
}

int main()
{
    vector<int> r = {1,2,3,4};
    vector<int> res  = self_product(r);
    for(int i : res)
    {
        cout << i << endl;
    }
    return 0;
}