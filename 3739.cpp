// count subarray with majority element 2

Constraints:

// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^9
// 1 <= target <= 10^9

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> bit;
    int bit_size;

    // Standard Fenwick Tree point update
    void update(int idx, int val) {
        for (; idx < bit_size; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    // Standard Fenwick Tree prefix sum query
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // The prefix sum ranges from -n to +n. 
        // We shift by (n + 1) to make indices 1-based for the Fenwick Tree.
        bit_size = 2 * n + 2;
        bit.assign(bit_size, 0);

        long long total_subarrays = 0;
        int current_pref = 0;

        // Insert the initial prefix sum of 0 before processing elements
        update(current_pref + n + 1, 1);

        for (int num : nums) {
            // Step 1: Update current prefix sum
            if (num == target) {
                current_pref += 1;
            } else {
                current_pref -= 1;
            }

            // Step 2: Query how many previous prefix sums are strictly less than current_pref
            // Mapped index for current_pref is (current_pref + n + 1). 
            // Strictly less means querying up to (current_pref + n).
            total_subarrays += query(current_pref + n);

            // Step 3: Insert the current prefix sum into the Fenwick Tree
            update(current_pref + n + 1, 1);
        }

        return total_subarrays;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 1, 3, 1, 5, 4};
    int target = 2;
    cout << s.countMajoritySubarrays(nums, target) << endl;
    return 0;
}
