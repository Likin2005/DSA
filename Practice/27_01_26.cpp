#include<bits/stdc++.h>
using namespace std;

//PREFIX SUM + HASHMAP
// key -> prefix sum and value -> count
int Subarray_count(vector<int> num,int target)
{
    if(num.empty()) return 0;
    unordered_map<int, int> seen;
    seen[0] = 1;
    int count = 0, sum = 0, x = num.size();
    for(int i=0;i<x;i++)
    {
        sum += num[i];

        if(seen.find(sum-target) != seen.end())
        {
            count += seen[sum-target];
        }

        seen[sum]++;
    }
    return count;
}

int longest_subarray(vector<int> num, int target)
{
    if(num.empty()) return 0;
    int sum = 0, len = 0, x = num.size();
    unordered_map<int,int> seen;
    for(int i=0;i<x;i++)
    {
        sum += num[i];

        if(sum == target)
        {
            len = 1 + i;
        }

        if(seen.find(sum - target) != seen.end())
        {
            len = max(len, i - seen[sum - target]);
        }

        if(seen.find(sum) == seen.end())
        {
            seen[sum] = i;
        }
    }
    return len;
}

int main()
{
    vector<int> num = {3,4,-7,1,3,3,1,4,-1};
    cout << longest_subarray(num, 7) << endl;
    return 0;
}