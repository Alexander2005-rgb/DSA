// wap to find the common prfic in the string
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     string longestCommonPrefix(vector<string> &strs)
     {
          if (strs.empty())
          {
               return "";
          }
          string prefix = strs[0];
          for (int i = 1; i < strs.size(); ++i)
          {
               while (strs[i].find(prefix) != 0)
               {
                    prefix = prefix.substr(0, prefix.length() - 1);
                    if (prefix.empty())
                    {
                         return "";
                    }
               }
          }
          return prefix;
     }
     string longestCommonPrefix1(vector<string> &strs)
     {
          string ans = "";
          for (int i = 0; i < strs[0].size(); i++)
          {
               char ch = strs[0][i];
               for (int j = 1; j < strs.size(); j++)
               {
                    if (i >= strs[j].size() || strs[j][i] != ch)
                    {
                         return ans;
                    }
               }
               ans += ch;
          }
          return ans;
     }
};
int main()
{
     Solution v;
     vector<string> strs = {"flower", "flow", "flight"};
     cout << v.longestCommonPrefix(strs) << endl;
     cout << v.longestCommonPrefix1(strs);
     return 0;
}
