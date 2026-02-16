#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) 
{
    while(b!=0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int sum(void)
{
    int a,b;
    cout << "Enter the first number and second number : " << endl;
    cin >> a >> b;
    return a+b;
}

pair<int,int> pair_sum(vector<int> &n,int target)
{
    pair<int,int> res;
    int left = 0, right = n.size()-1;
    while(left < right)
    {
        if(n[left] + n[right] == target)
        {
            res.first = n[left], res.second = n[right];
            return res;
        }
        else if(n[left] + n[right] > target)
        {
            right--;
        }
        else{
            left++;
        }
    }
}

int majority_element(vector<int> res)
{
    sort(res.begin(),res.end());
    int freq = 0, ans = 0;
    for(int i=1;i<res.size()-1;i++)
    {
        if(freq == 0)
        {
            ans = res[i];
        }
        if(ans == res[i])
        {
            freq++;
        }
        else{
            freq--;
        }
    }
    return ans;
}

int main()
{
    vector<int> r = {0,0,1,1,1,1,1,2};
    cout << majority_element(r) << endl;
    return 0;
}