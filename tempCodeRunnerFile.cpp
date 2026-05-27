// maximum enemy6 forts that can be captured
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     int maxEnemyFort(vector<int> &forts)
     {
          {
               int count = 0, max_count = 0;
               for (int i = 0; i < forts.size(); i++)
               {
                    {
                         if (forts[0] == 0 && forts[forts.size() - 1] == -1)
                         {
                              count = 0;
                         }

                         else if (forts[i] == 0)
                         {
                              count++;
                         }
                         else if (forts[i] == 1)
                         {
                              count = 0;
                         }
                         else if (forts[i] == -1)
                         {
                              max_count = max(max_count, count);
                              count = 0;
                         }
                    }
               }
               return max_count;
          }
     }
};
int main()
{
     Solution obj;
     vector<int> forts = {1, 0, 1, -1, 0, 0, 0, -1};
     cout << obj.maxEnemyFort(forts) << endl;
     return 0;
}
