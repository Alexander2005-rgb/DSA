// string to integer
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     int myAtoi(string s)
     {
          int sign = 1, result = 0, i = 0;
          // discard all leading whitespaces
          while (i < s.length() && s[i] == ' ')
          {
               i++;
          }
          // sign check
          if (i < s.length() && (s[i] == '+' || s[i] == '-'))
          {
               sign = (s[i] == '-') ? -1 : 1; //(s[i] == '-') ? -1 : 1 means if s[i] is '-' then sign is -1 else sign is 1
               i++;
          }
          // convert number and avoid overflow
          while (i < s.length() && isdigit(s[i]))
          {
               int digit = s[i] - '0';
               // check for overflow
               if (result > (INT_MAX - digit) / 10)
               {
                    return (sign == 1) ? INT_MAX : INT_MIN;
               }
               result = result * 10 + digit;
               i++;
          }
          return result * sign;
     }
};
int main()
{
     Solution obj;
     string str = "  -042";
     cout << obj.myAtoi(str) << endl;
     return 0;
}