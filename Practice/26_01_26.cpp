#include<bits/stdc++.h>
using namespace std;

int largest(vector<int> &num)
{
    if(num.empty()) return -1;
    int big = num[0];
    for(int i : num)
    {
        if(i > big)
        {
            big = i;
        }
    }
    return big;
}

int second_largest(vector<int> &num)
{
    if(num.size() == 0 || num.size() == 1) return -1;
    int largest = INT_MIN, second = INT_MIN;
    for(int i : num)
    {
        if(i > largest)
        {
            second = largest;
            largest = i;
        }
        else if(i > second && i < largest)
        {
            second = i;
        }
    }
    return second;
}

vector<int> reverse(vector<int>& num)
{
    if(num.size() == 0) return {};
    if(num.size() == 1) return num;
    int left = 0, right = num.size()-1;
    while(left < right)
    {
        int temp = num[left];
        num[left] = num[right];
        num[right] = temp;
        left++, right--;
    }
    return num;
}

bool is_sorted(vector<int> num)
{
    if(num.size() == 0 || num.size() == 1) return true;
    int x = num.size();
    for(int i=1;i<x;i++)
    {
        if(num[i-1] > num[i])
        {
            return false;
        }
    }
    return true;
}

vector<int> move_zeros(vector<int> num)
{
    if(num.size() == 0) return {};
    if(num.size() == 1) return num;
    int index = 0, x = num.size();
    for(int i=0;i<x;i++)
    {
        if(num[i] != 0)
        {
            num[index++] = num[i];
        }
    }
    if(index < x-1)
    {
        while(index < x)
        {
            num[index++] = 0;
        }
    }
    return num;
}

int range_sum(vector<int> num, int left, int right)
{
    if(num.size() == 0) return 0;
    int sum = 0,x = num.size();
    for(int i=0;i<x;i++)
    {
        sum+=num[i];
        num[i] = sum;
    }
    if(left == 0)
    {
        return num[right];
    }
    else
    {
        return (num[right] - num[left-1]);
    }
}

int equilibrium_index(vector<int> num)
{
    if(num.empty()) return -1;
    if(num.size() == 1) return 0;
    
    int right_sum = accumulate(num.begin(), num.end(),0);
    int left_sum = 0, x = num.size();
    
    for(int i=0;i<x;i++)
    {
        right_sum-=num[i];

        if(left_sum == right_sum)
        {
            return i;
        }
        
        left_sum+=num[i];
    }
    return -1;
}

int main()
{
    vector<int> num = {1,1,0};
    return 0;
}