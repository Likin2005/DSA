#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    //1.
    // int a,b;
    // cin >> a;
    // cin >> b;
    // int max_power_two = 0;
    // int ans = 0;
    // for(int i=a;i<=b;i++)
    // {
    //     int temp = i;
    //     int count = 0;
    //     while(temp%2 == 0)
    //     {
    //         count++;
    //         temp = temp/2;
    //     }
    //     if(count > max_power_two)
    //     {
    //         max_power_two = count;
    //         ans = i;
    //     }
    // }
    // cout << "The maximum power of 2 is : " << ans << " power : " << max_power_two<< endl;
    //2.
    // // int num = 5678;
    // // int div = 21;
    // // while(num != 0)
    // // {
    // //     int rem = num % div;
    // //     if(rem<=9)
    // //     {
    // //         cout << rem;
    // //     }
    // //     else{
    // //         cout << char(rem+55);
    // //     }
    // //     num = num / div;
    // // }
    // //3.
    // // int entry[] = {3,5,2,0};
    // // int exit[] = {0,2,4,4};
    // // int T = 4;
    // // int max_num = 0;
    // // int present = 0;
    // // for(int i = 0;i<T;i++)
    // // {
    // //     present = present + entry[i] - exit[i];
    // //     if(max_num < present)
    // //     {
    // //         max_num = present;
    // //     }
    // // }
    // // cout << max_num;
    // //4.
    // string str = "1C0C1C1A0B1";
    // int res = str[0] - '0';
    // for(int i=0;i<str.length()-2;i+=2)
    // {
    //     int a = res;
    //     int b = str[i+2] - '0';
    //     char x = str[i+1];
    //     if(x == 'A')
    //     {
    //         res = a && b;
    //     }
    //     else if(x == 'B')
    //     {
    //         res = a || b;
    //     }
    //     else
    //     {
    //         res = a ^ b;
    //     }
    // } 
    // cout << res;
    int arr[] = {10,20,30,40,50};
    int n = 3;
    int size = sizeof(arr) / sizeof(int);
    for(int i=0;i<n;i++)
    {
        for(int j=size-1;j>0;j--)
        {
            int temp = arr[j];
            arr[j] = arr[0];
            arr[0] = temp;
        }
    }
    //int temp = arr[j];
    //arr[j] = arr[j-1];
    //arr[j-1] = temp;
    for(int i=0;i<size;i++)
    {
        cout << arr[i] << " ";
    }
    return 0; 
}