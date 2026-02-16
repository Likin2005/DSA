#include<bits/stdc++.h>
using namespace std;

/*Sliding Window technique*/

int maximum_subarray(vector<int> &num, int k)
{
    int x = num.size(), sum = 0, max_sum = 0;
    if(x < k) return -1;
    for(int i=0;i<k;i++)
    {
        sum += num[i];
    }

    max_sum = max(sum, max_sum);
    for(int i=k;i<x;i++)
    {
        sum = sum - num[i-k] + num[i];
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

vector<int> first_negative(vector<int> &num, int k)
{
    deque<int> neg;
    int x = num.size();
    vector<int> res;
    for(int i=0;i<x;i++)
    {
        if(num[i] < 0)
        {
            neg.push_back(i);
        }

        if(i >= k-1)
        {
            if(!neg.empty() && neg.front() < i-k+1)
            {
                neg.pop_front();
            }
            if(neg.empty())
            {
                neg.push_back(0);
            }
            else
            {
                neg.push_back(num[neg.front()]);
            }
        }
    }
    return res;
}

int longest_subarray(vector<int> &num, int k)
{
    int len = 0, max_len = 0, x = num.size(), sum = 0, left = 0;
    for(int right=0;right<x;right++)
    {
        sum += num[right];

        while(sum > k)
        {
            sum -= num[left];
            left++;
        }

        if(sum <= k)
        {
            len = right - left + 1;
            max_len = max(len, max_len);
        }
    }
    return max_len;
}

int main()
{
    vector<int> num = {2, 5, 1, 7, 10};
    cout << longest_subarray(num, 14) << endl;
    return 0;
}