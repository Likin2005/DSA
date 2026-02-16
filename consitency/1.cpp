#include<bits/stdc++.h>
using namespace std;

int largest_element(vector<int> n)
{
    int largest = INT_MIN;
    for(int i : n)
    {
        if(i > largest)
        {
            largest = i;
        }
    }
    return largest;
}

int second_largest(vector<int> n)
{
    int largest = INT_MIN, second = INT_MIN;
    for(int i : n)
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

bool is_sorted(vector<int> n)
{   
    int x = n.size(); 
    for(int i=1;i<x;i++)
    {
        if(n[i-1] > n[i])
        {
            return false;
        }
    }
    return true;
}

vector<int> remove_duplicates(vector<int> n)
{
    int index = 1,x = n.size(),item = n[0];
    for(int i=1;i<x;i++)
    {
        if(item != n[i])
        {
            n[index++] = n[i];
            item = n[i];
        }
    }
    if(index < x)
    {
        while(index != x)
        {
            n[index++] = 0;
        }
    }
    return n;
}

vector<int> left_rotate_by_one(vector<int> n)
{
    int item = n[0],x = n.size();
    for(int i=1;i<x;i++)
    {
        n[i-1] = n[i];
    }
    n[x-1] = item;
    return n;
}

vector<int> left_rotate_by_k(vector<int> n,int k)
{
    int x = n.size();
    k = k % x;
    reverse(n.begin(),n.end());
    reverse(n.begin(),n.begin()+k);
    reverse(n.begin()+k,n.end());
    return n;
}

vector<int> move_zeros_to_end(vector<int> n)
{
    int index = 0,x = n.size();
    for(int i : n)
    {
        if(i != 0)
        {
            n[index++] = i;
        }
    }
    if(index < x)
    {
        while(index != x)
        {
            n[index++] = 0;
        }
    }
    return n;
}

vector<int> union_vectors(vector<int> n1, vector<int> n2)
{
    int x = n1.size(), y = n2.size();
    int index_1 = 0, index_2 = 0;
    vector<int> union_vec;
    while(index_1 < x && index_2 < y)
    {
        if(n1[index_1] < n2[index_2])
        {
            if(union_vec.empty() || union_vec.back() != n1[index_1])
            {
                union_vec.push_back(n1[index_1]);
            }   
            index_1++;
        }
        else if(n1[index_1] > n2[index_2])
        {
            if(union_vec.empty() || union_vec.back() != n2[index_2])
            {
                union_vec.push_back(n2[index_2]);
            }
            index_2++;
        }
    }
    while(index_1 < x)
    {
        if(union_vec.empty() || union_vec.back() != n1[index_1])
        {
            union_vec.push_back(n1[index_1]);
        }
        index_1++;
    }
    while(index_2 < y)
    {
        if(union_vec.empty() || union_vec.back() != n2[index_2])
        {
            union_vec.push_back(n2[index_2]);
        }
        index_2++;
    }
    return union_vec;
}

vector<int> intersection(vector<int> n1, vector<int> n2)
{
    int index_1 = 0, index_2 = 0;
    int x = n1.size(), y = n2.size();
    vector<int> intersect;
    while(index_1 < x && index_2 < y)
    {
        if(n1[index_1] == n2[index_2])
        {
            if(intersect.empty() || intersect.back() != n1[index_1])
            {
                intersect.push_back(n1[index_1]);
            }
            index_1++,index_2++;
        }
        else if(n1[index_1] > n2[index_2])
        {
            index_2++;
        }
        else
        {
            index_1++;
        }
    }
    return intersect;
}   

int main()
{
    cout << "Likin, You can do it !!!" << endl;
    vector<int> n1 = {1,3,5,7,9};
    vector<int> n2 = {0,2,5,6,8,10}; 
    vector<int> res = intersection(n1,n2);
    for(int i : res)
    {
        cout << i << " "; 
    }
    return 0;
}