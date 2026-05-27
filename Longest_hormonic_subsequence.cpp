// Longest Harmonious Subsequence
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
     int findLHS(vector<int> &nums)
     {
          // usingf the order  map function
          map<int, int> freq;

          for (int num : nums)
          {
               freq[num]++;
          }

          int maxlen = 0;

          // traverse the map

          for (auto it : freq)
          {
               int key = it.first;
               int val = it.second;

               if (freq.count(key + 1))
               {
                    maxlen = max(maxlen, val + freq[key + 1]);
               }
          }

          return maxlen;
     }
     // using unordererdd map
     int findLHS1(vector<int> &nums)
     {
          unordered_map<int, int> freq;
          int maxlen = 0;
          for (int num : nums)
          {
               freq[num]++;
               if (freq.count(num + 1))
               {
                    maxlen = max(maxlen, freq[num] + freq[num + 1]);
               }
               if (freq.count(num - 1))
               {
                    maxlen = max(maxlen, freq[num] + freq[num - 1]);
               }
          }
          return maxlen;
     }
};
// using asliding window
int findLHS2(vector<int> &nums)
{
     sort(nums.begin(), nums.end());
     int maxlen = 0;
     int i = 0;
     for (int j = 0; j < nums.size(); j++)
     {
          while (nums[j] - nums[i] > 1)
          {
               i++;
          }
          if (nums[j] - nums[i] == 1)
          {
               maxlen = max(maxlen, j - i + 1);
          }
     }
     return maxlen;
}
int main()
{
     Solution sol;
     vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};

     cout << "using ordered map:" << sol.findLHS(nums) << endl;
     cout << "using unordered map:" << sol.findLHS1(nums) << endl;
     cout << "using sliding window:" << findLHS2(nums) << endl;

     return 0;
}