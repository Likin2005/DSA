#include<bits/stdc++.h>
using namespace std;

int sum(int n)
{
    int total = 0;
    if(n >= 0)
    {
        total = n + sum(n-1);
    }
    return total;
}

int sum_1(int n)
{
    if(n == 1) return 1;
    if(n == 0) return 0;
    int total = 0;
    for(int i=0;i<=n;i++)
    {
        total += i;
    }
    return total;
}

int sum_2(int n)
{
    return (n*(n+1))/2;
}

bool is_perfect(int n)
{
    if(n <= 1) return false;
    int sum_factors = 1; //1 is always a divisor
    for(int i=2;i<=n/2;i++)
    {
        if(n % i == 0)
        {
            sum_factors += i;
        }
    }
    sum_factors += n;
    return sum_factors == n*2;
}

int main()
{
    cout << is_perfect(28) << endl;
    return 0;
}