#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &num)
{
    int larg = num[num.size() - 1];
    vector<int> res = {larg};
    for(int i=num.size()-1-1;i>=0;i--)
    {
        if(num[i] > larg)
        {
            res.push_back(num[i]);
            larg = num[i];
        }
    }
    return res;
}

vector<int> rotate_vector(vector<int> &num, int k)
{
    k = k % num.size();
    reverse(num.begin(), num.end());
    reverse(num.begin(), num.begin()+k);
    reverse(num.begin()+k, num.end());
    return num;
}

bool rotations(string s, string t)
{
    s = s + s;
    for(int i=0;i<s.length()-t.length();i++)
    {
        string temp = s.substr(i, t.length());
        if(temp == t)
        {
            return true;
        }
    }
    return false;
}

int longest_one(vector<int> &one)
{
    int count = 0, max_count = 0;
    for(int i : one)
    {
        if(i == 1)
        {
            count++;
        }
        else
        {
            count=0;
        }
        max_count = max(count, max_count);
    }
    return max_count;
}

string reverse_word(string s)
{
    string res = "", temp = "";
    reverse(s.begin(), s.end());
    for(char i : s)
    {   //today is monday
        if(i == ' ')
        {
            if(!temp.empty())
            {
                reverse(temp.begin(), temp.end());
                res += temp;
                if(!res.empty())
                {
                    res += ' ';
                }
                temp.clear();
            }
        }
        else
        {
            temp += i;
        }
    }
    if(!temp.empty())
    {
        reverse(temp.begin(), temp.end());
        res += temp;
        temp.clear();
        if(!res.empty())res+=" ";
    }
    return res;
}

long long missing_number(vector<int> &num)
{
    long long prod = 1;
    int n = num[num.size()-1];
    prod = (n*(n+1))/2;
    for(int i : num)
    {
        prod -= i;
    }
    return prod;
}

bool is_pangram(string s)
{
    vector<bool>present(90,false);
    string res = "";
    for(char i : s)
    {
        res += toupper(i);
    }
    for(int i : res)
    {
        present[i] = true;
    }
    for(int i=65;i<=90;i++)
    {
        if(present[i] == false)
        {
            return false;
        }
    }
    return true;
}

int sum_of_digits(int num)
{
    int sum = 0;
    while(num != 0)
    {
        int digit = num % 10;
        num /= 10;
        sum += digit;
    }
    while(sum >= 9)
    {
        int temp = sum;
        sum = 0;
        int digit = temp % 10;
        temp /= 10;
        sum += digit;
    }
    return sum;
}

int longest_length_zero_one(vector<int> &num)
{
    unordered_map<int, int> seen;
    int len = 0;
    for(int i=0;i<num.size();i++)
    {
        seen[num[i]]++;
        if(seen[0] == seen[1])
        {
            len = max(len, i+1);
        }
    }
    return len;
}

vector<int> pos_neg_alternate(vector<int> &num)
{
    sort(num.begin(), num.end());
    int left = 1, right = num.size()-1-1;
    while(left < right)
    {
        swap(num[left], num[right]);
        left+=2, right-=2;
    }
    return num;
}

bool verify(char i, char j)
{
    return ((i == '(' && j == ')') || (i == '[' && j == ']') || (i == '{' && j == '}'));
}

bool valid_parenthesis(string str)
{
    stack<char> s;
    for(char i : str)
    {
        if(i == '(' || i == '[' || i == '{')
        {
            s.push(i);
        }
        else
        {
            if(s.empty()) return false;
            char temp = s.top();
            if(!verify(temp, i))
            {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

vector<int> sort_zero_one_two(vector<int> &num)
{
    int left = 0, mid = 0, right = num.size()-1;
    while(mid <= right)
    {
        if(num[mid] == 0)
        {
            swap(num[left], num[mid]);
            left++, mid++;
        }
        else if(num[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(num[mid], num[right]);
            right--;
        }
    }
    return num;
}

int search_sorted_array(vector<int> &num, int target)
{
    int left = 0, right = num.size()-1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(num[mid] == target)
        {
            return mid;
        }
        else if(num[left] < num[mid])
        {
            if(num[left] <= target && num[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if(num[mid] <= target && num[right] >= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> x = {50,40};
    // vector<int> res = sort_zero_one_two(x);
    // for(int i : res)
    // {
    //     cout << i << " ";
    // }
    cout << search_sorted_array(x, 40) << endl;
    return 0;
}