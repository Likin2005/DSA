#include<bits/stdc++.h>
using namespace std;

void print(int n)
{
    if(n > 100) return;
    cout << n << endl;
    print(n+1);
}

void decrease(int n)
{
    if(n == 0) return;
    cout << n << endl;
    decrease(n-1);
}

int main()
{
    decrease(100);
    return 0;
}