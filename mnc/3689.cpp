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
