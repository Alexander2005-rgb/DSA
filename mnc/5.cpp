// maximum subarray sum
#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum(int arr[], int n)
{
     int maxSoFar = INT_MIN;
     int currentMax = 0;
     for (int i = 0; i < n; i++)
     {
          currentMax += arr[i];
          if (currentMax > maxSoFar)
          {
               maxSoFar = currentMax;
          }
          if (currentMax < 0)
          {
               currentMax = 0;
          }
     }
     return maxSoFar;
}

class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {

        int currentSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            currentSum = max(nums[i],
                             currentSum + nums[i]);

            maxSum = max(maxSum,
                         currentSum);
        }

        return maxSum;
    }
};
int main()
{
     int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
     int n = sizeof(arr) / sizeof(arr[0]);
     cout << maxSubarraySum(arr, n) << endl;
     return 0;
}
