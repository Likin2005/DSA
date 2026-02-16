#include<bits/stdc++.h>
using namespace std;

int reverse(int number)
{
    int r = 0;
    while(number != 0)
    {
        r = r*10 + number%10;
        number /= 10;
    }
    return r;
}

int return_palindrome(int number)
{
    if(number <= 9 && number >= 0) return number;
    int res = number,temp;
    while(1)
    {
        temp = res;
        res = reverse(res);
        if(res == temp) break;
        res += temp;
    }
    return res;
}

int second_largest(vector<int> res)
{
    if(res.empty()) return -1;
    int largest = 0,second = 0;
    for(int i : res)
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

int main()
{
    vector<int> res = {1,2,3,4,5,5,6,6};
    cout << second_largest(res) << endl;
    return 0;
}