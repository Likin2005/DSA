#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> n = {1,2,3,4,5,6,7,8,9,10};
    int target = 15,start = -1,end = -1;
    for(int i=0;i<n.size();i++)
    {
        int sum = 0;
        for(int j=i;j<n.size();j++)
        {
            sum += n[j];
            if(sum == target)
            {
                start = i;
                end = j;
                break;
            }
        }
        if(start != -1) break;
    }
    if(start != -1) cout << "Start : " << start << "  End : "<< end << endl;
    return 0;
}