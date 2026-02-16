#include<iostream>
using namespace std;

int main()
{
    int arr[] = {-8,-6,1,5,7,9,10};
    int sum = 0;
    int max_sum = INT16_MIN;
    for(int i=0;i<7;i++)
    {
        sum += arr[i];
        max_sum = max(sum,max_sum);
        if(sum < 0)
        {
            sum = 0;
        }
    }
    // cout << max_sum;

    // int target = 2;
    // int i=0,j=6;
    // while(i<=j)
    // {
    //     if(arr[i] + arr[j] > target)
    //     {
    //         j--;
    //     }
    //     else if(arr[i] + arr[j] < target)
    //     {
    //         i++;
    //     }
    //     else{
    //         cout << i << ", " << j;
    //         break;
    //     }
    // }
    long x = 10;
    int y = 9;
    cout << x-y;
    return 0;
}