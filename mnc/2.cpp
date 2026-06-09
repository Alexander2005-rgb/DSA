// valid parentheses
/**
A string is valid if:

Every opening bracket has a corresponding closing bracket.

Brackets close in the correct order.
 
Examples:

Input: s = "()"
Output: true

Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false

by oberving this example we thing or remember it untill the matching clsing bracket arrives

he best data structure to use for it is the stack (last in first out)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isValid(string s)
    {
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                char top = st.top();
                st.pop();
                if((s[i] == ')' && top != '(') || (s[i] == ']' && top != '[') || (s[i] == '}' && top != '{'))
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution s;
    string str;
    cin >> str;
    if(s.isValid(str))
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "invalid" << endl;
    }
    return 0;
}