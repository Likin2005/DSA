#include<iostream>
#include<math.h>
using namespace std;

int sum(int n)
{
    return (n*(n+1))/2;
}

int fact(int n)
{
    int pro = 1;
    if (n==1 || n==0)
    {
        return 1;
    }
    return n*fact(n-1);
    // return pro;
}

int sum_of_digits(int number)
{
    int remainder,total=0;
    while(number!=0)
    {
        remainder = number%10;
        total+=remainder;
        number = number/10;
    }
    return total;
}

int binomial_cofficient(int n,int r)
{
    if(n>r)
    {
        return (fact(n)/(fact(r)*fact(n-r)));
    }
    else{
        return -1;
    }
}

int decimal_to_binary(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        int binary = 0;
        int x = 1;
        while(n!=0)
        {
            int remainder = n%2;
            n = n/2;
            binary = binary + remainder*x;
            x=x*10;
        }
        return binary;
    }
}

int binary_to_decimal(int bin)
{
    if(bin == 0)
    {
        return 0;
    }
    else if(bin == 1)
    {
        return 1;
    }
    else
    {
        int x = 1,num = 0;
        while(bin != 0)
        {
            int remainder = bin%10;
            bin/=10;
            num += x*remainder;
            x*=2;
        }
        return num;
    }
}

int reverse(int n)
{
    int num = 0;
    while(n!=0)
    {
        int remainder = n % 10;
        n/=10;
        num = 10*num + remainder;
    }
    return num;
}

int remainder(int num)
{
    int total = 0;
    while(num != 0)
    {
        int quotient = num / 5;
        total += quotient;
        num /= 5;
    }
    return total;
}


int main()
{
    signed int age = 10;
    cout << reverse(152) << endl;
    return 0;
}