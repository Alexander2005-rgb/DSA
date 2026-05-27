// minimum value to get positive step by step sum
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
     int minStartValue(vector<int> &nums)
     {
          int min_sum = 0, curr_sum = 0;
          for (int i = 0; i < nums.size(); i++)
          {
               curr_sum += nums[i];
               min_sum = min(min_sum, curr_sum);
          }
          return 1 - min_sum;
     }
};
int main()
{
     Solution obj;
     vector<int> nums = {-3, 2, -3, 4, 2};
     cout << obj.minStartValue(nums) << endl;
     return 0;
}