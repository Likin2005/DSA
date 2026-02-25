#include<bits/stdc++.h>
using namespace std;

vector<int> third_larget(vector<int> &num)
{
    if(num.empty()) return {};
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    for(int i : num)
    {
        if(i > first)
        {
            third = second;
            second = first;
            first = i;
        }
        if(i < first && i > second)
        {
            third = second;
            second = i;
        }
        if(i < first && i < second && i > third)
        {
            i = third;
        }
    }
    return {first, second, third};
}

int range_sum(vector<int> &num, int left, int right)
{
    if(num.empty()) return 0;
    int sum = 0;
    for(int i=0;i<num.size();i++)
    {
        sum += num[i];
        num[i] = sum;
    }
    if(left == 0) return num[right-1];
    else return num[right] - num[left-1];
}

int equilibrium_index(vector<int> &num)
{
    if(num.empty()) return -1;
    if(num.size() == 1) return 0;
    
    int right_sum = accumulate(num.begin(), num.end(), 0);
    int left_sum = 0;

    for(int i=0;i<num.size();i++)
    {
        right_sum -= num[i];

        if(left_sum == right_sum) return i;

        left_sum += num[i];
    }
    return -1;
}

int count_subarray(vector<int> &num, int target)
{
    if(num.empty()) return 0;
    unordered_map<int, int> seen;
    int sum = 0, count = 0;
    seen[0] = 1;

    for(int i=0;i<num.size();i++)
    {
        sum += num[i];

        if(seen.find(sum - target) != seen.end())
        {
            count += seen[sum - target];
        }

        seen[sum]++;
    }
    return count;
}

int longest_subarray(vector<int> &num, int target)
{
    if(num.empty()) return 0;
    unordered_map<int, int> seen;
    int sum = 0, len = 0;

    for(int i=0;i<num.size();i++)
    {
        sum += num[i];

        if(sum == target)
        {
            len = i + 1;
        }

        if(seen.find(sum - target) != seen.end())
        {
            len = max(len, i - seen[sum - target]);
        }

        if(seen.find(sum - target) == seen.end())
        {
            seen[sum] = i;
        }
    }
    return len;
}

int main()
{
    vector<int> res = {12,3,4,5,2,1,1,2,1,1,1,1,1,1,7};
    cout << longest_subarray(res, 7) << endl;
    return 0;
}