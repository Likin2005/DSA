#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    if(n == 0 || n == 1) return false;
    for(int i=2;i<=n/2;i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int count_prime(int n)
{
    if(n == 0 || n == 1) return 0;
    int count = 0;
    for(int i=2;i<n;i++)
    {
        if((is_prime(i)))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    cout << count_prime(1) << endl;
    return 0;
}