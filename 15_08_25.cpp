#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<set>
using namespace std;

vector<int> rotate_array(vector<int>&n, int k)
{
    int count = 0, x = n.size();
    while(count < k)
    {
        int item = n[x-1];
        for(int i=x-1;i>0;i--)
        {
            n[i] = n[i-1];
        }
        n[0] = item;
        count++;
    }
    return n;
}

bool valid_parindrome(const string&s)
{
    if(s.empty()) return true;
    string new_string = "";
    for(char i : s)
    {
        if(isalpha(i))
        {
            new_string += tolower(i);
        }
        else if(int(i) >= 48 && int(i) < 58)
        {
            new_string += i;
        }
    }

    int i=0,j=new_string.size()-1;
    while(i <= j)
    {
        if(new_string[i] != new_string[j])
        {
            return false;
        }
        i++,j--;
    }
    return true;
}

vector<int> product(vector<int>& n)
{
    int x = n.size();
    vector<int> left(x,1), right(x,1), answer(x);
    for(int i = 1;i<x;i++)
    {
        left[i] = left[i-1] * n[i-1];
    }

    for(int i = x-2;i>= 0;i--)
    {
        right[i] = right[i+1] * n[i+1];
    }

    for(int i=0;i<x;i++)
    {
        answer[i] = left[i] * right[i];
    }
    return answer;
}

#define M 20
int stack[M];
int top = -1;
void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int evaluate(const string & s)
{
    for(char i : s)
    {
        if(isdigit(i))
        {
            push(i-'0');
        }
        else    
        {
            int b = pop();
            int a = pop();
            int temp;
            switch(i)
            {
                case '+' :  temp = a+b;break;
                case '-' :  temp = a-b;break;
                case '/' :  temp = a/b;break;
                case '*' :  temp = a*b;break;
            }
            push(temp);
        }
    }
    return pop();
}

int main()
{
    string str = "23+5*";
    cout << evaluate(str) << endl;
    return 0;
}