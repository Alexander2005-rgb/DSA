// max consecutive ones
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     int findMaxConsecutiveOnes(vector<int> &nums)
     {
          int count = 0, max_count = 0;
          for (int i = 0; i < nums.size(); i++)
          {
               if (nums[i] == 1)
               {
                    count++;
                    max_count = max(max_count, count);
               }
               else
               {
                    count = 0;
               }
          }
          return max_count;
     }
};
int main()
{
     Solution obj;
     vector<int> nums = {1, 1, 0, 1, 1, 1};
     cout << obj.findMaxConsecutiveOnes(nums) << endl;
     return 0;
}