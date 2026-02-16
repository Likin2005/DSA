#include<iostream>
#include<math.h>
using namespace std;

bool is_power_of_two(int num)
{
    int temp = num;
    if(num == 0)return false;
    else if(num == 1) return false;
    else
    {
        int i=0;
        while(num!=0)
        {
            num = num >> 1;
            i++;
        }
        if((int)pow(2,i-1) == temp)
        {
            return true;
        }
        return false;
    }
    
}

void reverse(int* arr, int i, int j)
{
    if(i >= j)
        return;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    reverse(arr, i+1, j-1);
}

int smallest(int* arr,int size)
{
    int small = INT16_MAX;
    for(int i=0;i<size;i++)
    {
        small = min(small,arr[i]);
    }
    return small;
}

int largest(int* arr,int size)
{
    int large = INT16_MIN;
    for(int i=0;i<size;i++)
    {
        if(large < arr[i])
        {
            large = arr[i];
        }
    }
    return large;
}

int linear_search(int arr[],int key,int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void reverse_array(int* arr,int size)
{
    int i=0,j=size-1;
    while(i<=j)
    {
        swap(arr[i],arr[j]);
        i++,j--;
    }
}

void duplicates(int* a,int s)
{
    for(int i=0;i<s;i++)
    {
        bool present = false;
        for(int j=i+1;j<s;j++)
        {
            if(a[i] == a[j])
            {
                present = true;
                break;
            }
        }
        if(!present)
        {
            cout << a[i] << " ";
        }
    }
}

int main()
{
    int a[] = {1,4,2,2,1,1};
    int s = 6;
    duplicates(a,s);
    return 0;
}   