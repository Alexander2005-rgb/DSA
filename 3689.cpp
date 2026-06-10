// maximum total subaeeay value 1

/*
You are given a 0-indexed integer array nums of length n and an integer k.

The value of a subarray is defined as:

product of all elements in the subarray.
multiplied by the minimum element in the subarray.
multiplied by the length of the subarray.
Return the maximum value among all subarrays of nums. 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxVal = nums[0], minVal = nums[0];
        for (int num : nums) {
            maxVal = max(maxVal, num);
            minVal = min(minVal, num);
        }
        return (long long)k * (maxVal - minVal);
    }
};
int main (){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 10;
    cout << s.maxTotalValue(nums, k) << endl;
    return 0;
}