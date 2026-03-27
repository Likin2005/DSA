#include<bits/stdc++.h>
using namespace std;

void rotate_array(vector<int> &arr, int d)
{
    d = d % arr.size();
    reverse(arr.begin(), arr.begin()+d);
    reverse(arr.begin()+d, arr.end());
    reverse(arr.begin(), arr.end());
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> res;
    res.push_back({});
    for(int i=0;i<nums.size();i++)
    {
        vector<int> temp;
        for(int j=i;j<nums.size();j++)
        {
            temp.push_back(nums[j]);
            res.push_back(temp);
        }
        temp.clear();
    }
    return res;
}

int main()
{
    vector<int> res = {1,2,3,4,5};
    vector<vector<int>> x = subsets(res);
    for(auto & y : x)
    {
        for(int i : y)
        {
            cout << i << " ";
        }
    }
    return 0;
}