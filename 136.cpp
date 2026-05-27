// find the single number in an array where every other element appears twice

#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int single = 0;
        for (int i = 0; i < n; i++) {
            single ^= nums[i];
        }
        return single;
    }
};