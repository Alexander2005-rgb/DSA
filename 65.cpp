// check valid number
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     bool isNumber(string s)
     {
          int i = 0;
          // skip leading spaces
          while (i < s.length() && s[i] == ' ')
               i++;
          // optional sign
          if (i < s.length() && (s[i] == '+' || s[i] == '-'))
               i++;
          bool isNumeric = false;
          // digits before decimal point
          while (i < s.length() && isdigit(s[i]))
          {
               isNumeric = true;
               i++;
          }
          // decimal point
          if (i < s.length() && s[i] == '.')
          {
               i++;
               // digits after decimal point
               while (i < s.length() && isdigit(s[i]))
               {
                    isNumeric = true;
                    i++;
               }
          }
          // exponent part
          if (isNumeric && i < s.length() && (s[i] == 'e' || s[i] == 'E'))
          {
               i++;
               isNumeric = false;
               // optional sign after exponent
               if (i < s.length() && (s[i] == '+' || s[i] == '-'))
                    i++;
               // digits after exponent
               while (i < s.length() && isdigit(s[i]))
               {
                    isNumeric = true;
                    i++;
               }
          }
          // skip trailing spaces
          while (i < s.length() && s[i] == ' ')
               i++;
          return isNumeric && i == s.length();
     }
};
int main()
{
     Solution obj;
     string str = "  -42.3e+7  ";
     cout << (obj.isNumber(str) ? "true" : "false") << endl;
     return 0;
}