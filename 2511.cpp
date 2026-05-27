// maximum enemy6 forts that can be captured
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     int captureForts(vector<int> &forts)
     {
          int max_captures = 0;
          for (int i = 0; i < forts.size(); i++)
          {
               if (forts[i] == 1)
               {
                    int captures = 0;
                    for (int j = i + 1; j < forts.size(); j++)
                    {
                         if (forts[j] == 0)
                         {
                              captures++;
                         }
                         else if (forts[j] == -1)
                         {
                              max_captures = max(max_captures, captures);
                              break;
                         }
                         else
                         {
                              break;
                         }
                    }
               }
               else if (forts[i] == -1)
               {
                    int captures = 0;
                    for (int j = i + 1; j < forts.size(); j++)
                    {
                         if (forts[j] == 0)
                         {
                              captures++;
                         }
                         else if (forts[j] == 1)
                         {
                              max_captures = max(max_captures, captures);
                              break;
                         }
                         else
                         {
                              break;
                         }
                    }
               }
          }
          return max_captures;
     }
};
int main()
{
     Solution obj;
     vector<int> forts = {0, 0, 0, -1, 0, 0, 0, 0, -1};
     cout << obj.captureForts(forts) << endl;
     return 0;
}