// wap to an array is monotonic if it si either monotone increasing or monotone decreasing

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     bool isMonotonic(vector<int> &nums)
     {

          bool increase = true;
          bool decrease = true;
          for (int i = 0; i < nums.size() - 1; i++)
          {
               if (nums[i] > nums[i + 1])
               {
                    increase = false;
               }
               if (nums[i] < nums[i + 1])
               {
                    decrease = false;
               }
          }
          return increase || decrease;
     }
};
int main()
{
     Solution s;
     vector<int> nums = {1, 4, 2, 3};
     cout << s.isMonotonic(nums);
     return 0;
}
