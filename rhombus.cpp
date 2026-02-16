#include<iostream>
#include<vector>
#define N 10
using namespace std;

vector<int> two_sum(vector <int> vec,int target)
{
    vector<int> ans;
    int n=vec.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(vec[i]+vec[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

int main()
{
    // int minimum = INT16_MAX,maximum = INT16_MIN;
    // int arr[N];
    // cout << "Enter the elements into the array  : ";
    // for(int i=0;i<N;i++)
    // {
    //     cin >> arr[i];
    // }
    // for(int i=0;i<N;i++)
    // {
    //     minimum = min(arr[i],minimum);
    //     maximum = max(arr[i],maximum);
    // }
    // cout << "Maximum : "<< maximum << " Minimum : " << minimum<< endl;
    // return 0;

    // int arr[] = {20,-49,-27,1,-9,5,-19,46,-100};
    // int index = 0;
    // int size = sizeof(arr)/sizeof(int);
    // for(int i=0;i<size;i++)
    // {
    //     if(arr[i] < 0)
    //     {
    //         arr[i] = arr[i] + arr[index];
    //         arr[index] = arr[i] - arr[index];
    //         arr[i] = arr[i] - arr[index];
    //         index++;
    //     }
    // }
    // for(int i=0;i<size;i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // int arr[] = {10,8,-4,17,-9,3,-15};
    // int sum = 0,size = sizeof(arr)/sizeof(int),k;
    // cout << "Enter the sum : ",
    // cin >> k;
    // int start,end;
    // for(int i=0;i<size;i++)
    // {
    //     sum = 0;
    //     for(int j=i;j<size;j++)
    //     {
    //         sum += arr[j]; 
    //         if(sum == k)
    //         {
    //             start = i;
    //             end = j;
    //             break;
    //         }
    //     }
    // }   
    // cout << "The subarray with the sum " << k << " is : "<<endl;
    // for(int i=start;i<=end;i++)
    // {
    //     cout << arr[i] << " ";
    // }

    //Patterns
    // int n;
    // cout << "Enter the value of n : "<<endl;
    // cin >> n;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<=i;j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }


    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<(n-i-1);j++)
    //     {
    //         cout << " ";
    //     }
    //     for(int k=1;k<=i+1;k++)
    //     {
    //         cout << k;
    //     }
    //     for(int x=i;x>0;x--)
    //     {
    //         cout << x;
    //     }
    //     cout << endl;
    // }

    //       1
    //     1 2 1
    //    1 3 3 1
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<(n-i-1);j++)
    //     {
    //         cout << " ";
    //     }
    //     int val = 1;
    //     for(int k=0;k<i+1;k++)
    //     {
    //         cout << val << " ";
    //         val = val*(i-k)/(k+1);
    //     }
    //     cout << endl;
    // }

    // string str = "kannada";
    // int i=0,j=str.size()-1;
    // bool is_palindrome = true;
    // while(i<=j)
    // {
    //     if(str[i] != str[j])
    //     {
    //         is_palindrome = false;
    //         break;
    //     }
    //     i++,j--;
    // }
    // (is_palindrome) ? cout << "Palindrome"  : cout << "Not Palindrome";
    // int vowels=0,consonants=0,spaces=0,digits=0;
    // for(int i=0;i<str.size();i++)
    // {
    //     if(str[i] == 'a'||str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
    //     {
    //         vowels++;
    //     }
    //     else if(str[i] == ' ')
    //     {
    //         spaces++;
    //     }
    //     else if(int(str[i]) >= 49 && int(str[i]) <= 58){
    //         digits++;
    //     }
    //     else{
    //         consonants++;
    //     }
    // }
    // cout << "Vowels : "<<vowels << " Consonents : " << consonants << " Spaces : " << spaces << " Digits : " << digits<< endl;

    // string max_str = "";
    
    return 0;
}