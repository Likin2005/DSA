#include<bits/stdc++.h>
using namespace std;

vector<int> two_sum(vector<int>& n, int target)
{
    if(n.empty()) return {-1, -1};
    int left = 0, right = n.size() - 1;
    while(left < right)
    {
        if(n[left] + n[right] == target)
        {
            return {left, right};
        }
        else if(n[left] + n[right] > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
}

int kadane_s(vector<int>& num)
{
    if(num.empty()) return 0;
    int sum = num[0], max_sum = num[0];
    for(int i=1;i<num.size();i++)
    {
        sum = max(num[i], sum + num[i]);
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}

int main()
{
    vector<int> n = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << kadane_s(n) << endl;
    return 0;
}