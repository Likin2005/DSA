// FUNCTIONS

#include<iostream>
#include<cmath>

using namespace std;

int fact(int n)
{
    int fact = 1;
    for(int i=1;i<=n;i++)
    {
        fact = fact * i;
    }
    return fact;
}

int strong_number(int n)
{
    int temp = n,sum = 0;
    while( n != 0)
    {
        int digit = n % 10;
        sum = sum + fact(digit);
        n = n / 10;
    }
    return temp == sum ;
}

int main()
{
    int radius;
    cout << "Enter the number : " << endl;
    cin >> radius ;
    strong_number(radius) ? cout << "Strong Number" : cout << "Not a strong number";
    return 0;
}