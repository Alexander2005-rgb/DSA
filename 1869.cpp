// longer contigous segment of ones than zeros
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     bool checkZeroOnes(string s)
     {
          int count1 = 0, count0 = 0, max_count1 = 0, max_count0 = 0;
          for (int i = 0; i < s.size(); i++)
          {
               if (s[i] == '1')
               {
                    count1++;
                    max_count1 = max(max_count1, count1);
                    count0 = 0;
               }
               else
               {
                    count0++;
                    max_count0 = max(max_count0, count0);
                    count1 = 0;
               }
          }
          return max_count1 > max_count0;
          }
};
int main()
{
     Solution obj;
     string s = "1101";
     cout << obj.checkZeroOnes(s) << endl;
     return 0;
}