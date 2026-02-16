#include<bits/stdc++.h>
using namespace std;

vector<int> rotate_array(vector<int> &arr,int k)
{
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    return arr;
}

bool is_sorted(vector<int> &arr)
{
    int x = arr.size();
    for(int i=1;i<x;i++)
    {
        if(arr[i-1] >= arr[i])
        {
            return false;
        }
    }
    return true;
}

vector<int> remove_duplicates(vector<int> &arr)
{
    vector<int> uniques;
    int x = arr.size(),item = arr[0];
    uniques.push_back(arr[0]);
    for(int i=1;i<x;i++)
    {
        if(item != arr[i])
        {
            item = arr[i];
            uniques.push_back(arr[i]);
        }
    }
    return uniques;
}

vector<int> remove_duplicates_1(vector<int> &arr)
{
    int x = arr.size(),item = arr[0],index = 1;
    for(int i=1;i<x;i++)
    {
        if(item != arr[i])
        {
            item = arr[i];
            arr[index++] = item;
        }
    }
    return arr;
}

int main()
{
    vector<int> a = {1,1,2,3,3,3,3,4,4,5,5,5,5,6,6,7,7};
    vector<int> res = remove_duplicates(a);
    for(int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> res_1 = remove_duplicates_1(a);
    for(int i : res_1)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}