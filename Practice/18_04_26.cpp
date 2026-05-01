#include<bits/stdc++.h>
using namespace std;

int* arr = new int[2];
int* pointer(int* a, int* b)
{
    int alice = 0, bob = 0;
    for(int i=0;i<3;i++)
    {
        if(*(a+i) > *(b+i))alice++;
        else if (*(a+i) < *(b+i)) bob++;
        else continue;
    }
    arr[0] = alice;
    arr[1] = bob;
    return arr;
}

int main()
{
    int a[] = {1,2,3};
    int b[] = {3,2,1};
    int res[2];
    pointer(a, b);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}