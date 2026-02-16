#include<bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) 
{
    int last_index = s.size()-1;
    int count = 0;
    if(s[last_index] == ' ')
    {
        while(s[last_index] == ' ')
        {
            last_index--;
        }
        while(s[last_index] != ' ')
        {
            count++;
            last_index--;
        }
    }
    else if(s.size() == 1)
    {
        return 1;
    }
    else
    {
        while(s[last_index] != ' ')
        {
            count++;
            last_index--;
        }
    }
    return count;
}

// bool is_isotropic(string s, string t)
// {   // paper == title, egg == add
//     if(s.length() != t.length()) return false;
//     unordered_map<char,char> x;
//     for(int i=0;i<s.length();i++)
//     {
//         if(x.find(s[i]))
//         {

//         }
//     }

// }

int main()
{
    struct car
    {
        int model;
        string name;
    };
    car car1;
    car1.model = 1967;
    car1.name = "Ford Mustang";
    cout << car1.model << endl;
    return 0;
}