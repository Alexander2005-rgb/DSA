// Problem 3737. LeetCode 3228. Count Subarrays with Majority Element 1
#include<bits./stdc++.h>
using namespace std;

class Solution {
public:
    // Using Fenwick Tree
    int countMajoritySubarrays(std::vector<int>& nums, int target) {
        int n = nums.size();
        
        // The prefix sum/balance can range from -n to +n.
        // We use an offset of `n` to safely index negative balances.
        // Max size needed: 2 * n + 1
        std::vector<int> freq(2 * n + 1, 0);
        
        // Initial state: A prefix sum of 0 has occurred 1 time (before elements start).
        int current_prefix = 0;
        freq[0 + n] = 1;
        
        long long total_subarrays = 0;
        
        // `smaller_prefixes_count` keeps a running count of how many 
        // previously stored prefix sums are strictly smaller than the `current_prefix`.
        int smaller_prefixes_count = 0;
        
        for (int num : nums) {
            if (num == target) {
                // When moving from prefix to prefix + 1:
                // All old prefixes that were equal to the old prefix value 
                // now become strictly smaller than our new prefix value.
                smaller_prefixes_count += freq[current_prefix + n];
                current_prefix += 1;
            } else {
                // When moving from prefix to prefix - 1:
                // The prefixes that were equal to the new prefix value 
                // are no longer strictly smaller than it.
                current_prefix -= 1;
                smaller_prefixes_count -= freq[current_prefix + n];
            }
            
            // Add the valid combinations found so far
            total_subarrays += smaller_prefixes_count;
            
            // Record the current prefix balance into the frequency map
            freq[current_prefix + n]++;
        }
        
        return total_subarrays;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 3, 2, 1, 4};
    int target = 3;
    cout << s.countMajoritySubarrays(nums, target) << endl;
    return 0;
}
    

