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

int main()
{
    vector<int> r = {1,2,3,4,-5,-5,-1};
    cout << max_product(r) << endl;
    return 0;
}