#include<bits/stdc++.h>
using namespace std;

int container_most_water(vector<int>& height)
{
    if(height.empty()) return 0;
    int left = 0, right = height.size()-1, max_area = 0;
    while (left < right)
    {
        int width = right - left;
        int area = width * min(height[left], height[right]);
        max_area = max(max_area, area);

        if(height[left] < height[right])
        {
            left++;
        }
        else if(height[left] > height[right])
        {
            right--;
        }
        else
        {
            left++, right--;
        }
    }
    return max_area;
}

int main()
{
    vector<int> n = {6,2,5,4};
    cout << container_most_water(n) << endl;
    return 0;
}