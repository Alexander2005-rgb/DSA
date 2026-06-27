//find the maximum number  of elelemnt in the subset

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int max_len = 0;

        // Handle the special case for 1
        if (count.count(1)) {
            int count_ones = count[1];
            max_len = (count_ones % 2 == 0) ? count_ones - 1 : count_ones;
        }

        // Check for other numbers as the base of the chain
        for (auto& [val, freq] : count) {
            if (val == 1) continue;

            long long current = val;
            int local_len = 0;

            // Build the chain as long as we have at least 2 elements of the current value
            while (count.count(current) && count[current] >= 2) {
                local_len += 2;
                current = current * current; // Move to the next square
                
                // Prevent overflow and unnecessary checks beyond the constraints
                if (current > 1e9) break;
            }

            // Check if the final squared element can act as the peak
            if (count.count(current) && count[current] >= 1) {
                local_len += 1;
            } else {
                // If there's no valid peak ahead, the last element we counted 
                // must act as the peak instead of a regular pair contributor.
                local_len -= 1;
            }

            max_len = max(max_len, local_len);
        }

        return max_len;
    }
};