// transforming array
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     vector<int> constructTransformedArray(vector<int> &nums)
     {
          int n = nums.size();
          vector<int> result(n);
          for (int i = 0; i < n; i++)
          {
               if (nums[i] > 0)
               {
                    int new_index = (i + nums[i]) % n;
                    result[i] = nums[new_index];
               }
               else if (nums[i] < 0)
               {
                    int new_index = (i + nums[i] % n + n) % n;
                    result[i] = nums[new_index];
               }
               else
               {
                    result[i] = nums[i];
               }
          }
          return result;
     }
};
int main()
{
     Solution s;
     vector<int> nums = {2, -1, 1, 2, 2};
     vector<int> result = s.constructTransformedArray(nums);
     for (int i : result)
     {
          cout << i << " ";
     }
     cout << endl;
     return 0;
}