// consecutive character
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     int maxPower(string s)
     {
          int count = 1, max_count = 1;
          for (int i = 1; i < s.size(); i++)
          {
               if (s[i] == s[i - 1])
               {
                    count++;
                    max_count = max(max_count, count);
               }
               else
               {
                    count = 1;
               }
          }
          return max_count;
     }
};
int main()
{
     Solution obj;
     string s = "leetcode";
     cout << obj.maxPower(s) << endl;
     return 0;
}
