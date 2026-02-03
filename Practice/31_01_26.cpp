#include<bits/stdc++.h>
using namespace std;

int longest_subaray(vector<int> &num, int target)
{
    if(num.empty()) return 0;
    int sum = 0, left = 0, x = num.size(), len = 0;
    for(int i=0;i<x;i++)
    {
        sum += num[i];

        while(sum > target)
        {
            sum -= num[left];
            left++;
        }

        if(sum <= target)
        {
            len = max(len, i-left+1);
        }
    }
    return len;
}

int longest_subarray(vector<int> &num, int target)
{
    if(num.empty()) return 0;
    int sum = 0, len = 0, x = num.size();
    unordered_map<int, int> seen;
    for(int i=0;i<x;i++)
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
}

pair<int, int> pair_sum(vector<int> &num, int target)
{
    if(num.empty()) return {-1,-1};
    int left = 0, right = num.size()-1;
    while(left < right)
    {
        if(num[left] + num[right] == target)
        {
            return {left, right};
        }
        if(num[left] + num[right] > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return {-1, -1};
}

void pairSum(vector<int> &num, int target)
{
    if(num.empty()) return;
    int left = 0, right = num.size() - 1, flag = 0;
    while(left < right)
    {
        if(num[right] + num[left] == target)
        {
            cout << num[left] << " " << num[right] << endl;
            left++, right--;
            flag = 1;
        }
        if(num[left] + num[right] > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    if(! flag)
    {
        cout << "No pairs found" << endl;
    }
}

void three_Sum(vector<int> &num, int target)
{
    int left = 0, right = num.size() - 1;
    bool found = false;
    sort(num.begin(), num.end());
    for(int i=0;i<num.size();i++)
    {
        int item = num[i];
        left = i + 1, right = num.size()-1;
        while(left < right)
        {
            if(num[left] + num[right] == target - item)
            {
                cout << item << " " << num[left] << " " << num[right] << endl;
                right--, left++;
                found = true;

                while(left < right && num[left] == num[left-1]) left++;
                while(left < right && num[right] == num[right+1]) right--;
            }
            if(num[left] + num[right] > target - item)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    if(! found)
    {
        cout << "No pairs found" << endl;
    } 
}

int main()
{
    vector<int> num = {-1,0,1,2,-1,-4};
    // pair<int, int> res = pair_sum(num, 6);
    three_Sum(num, 0);
    return 0;
}