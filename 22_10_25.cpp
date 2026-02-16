#include<bits/stdc++.h>
using namespace std;

vector<int> shift(vector<int> &arr, int k)
{
    int x = arr.size(),count = 0;
    while(k != count)
    {
        int temp = arr[0];
        for(int i=1;i<x;i++)
        {
            arr[i-1] = arr[i];
        }
        arr[x-1] = temp;
        count++;
    }
    return arr;
}

vector<int> move_zeros(vector<int> &z)
{
    int index = 0,x = z.size();
    for(int i=0;i<x;i++)
    {
        if(z[i] != 0)
        {
            z[index++] = z[i];
        }
    }
    while(index != x)
    {
        z[index++] = 0;
    }
    return z;
}

int main()
{
    vector<int> r = {1,0,2,0,3,0,4,0,5};
    vector<int> res =  move_zeros(r);
    for(int i : res)
    {
        cout << i << " ";
    }
    return 0;
}