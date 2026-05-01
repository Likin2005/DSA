#include<bits/stdc++.h>
using namespace std;

int number_of_count(vector<int>& num)
{
    sort(num.begin(), num.end());
    int count = 0, mid, n = num.size();
    if(n % 2 == 1)
    {
        mid = num[n / 2];
    }
    else
    {
        mid = (num[n / 2 - 1] + num[n / 2]) / 2;
    }
    for(int i : num)
    {
        count += abs(mid - i);
    }
    return count;
}

int main()
{
    vector<int> n = {4,6,7,1,2};
    cout << number_of_count(n);
    return 0;
}