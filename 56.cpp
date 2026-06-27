// merge intervals 
#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals based on the start value
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& a_next) {
            return a[0] < a_next[0];
        });

        vector<vector<int>> merged;

        for (const auto& interval : intervals) {
            // If the list of merged intervals is empty or if the current 
            // interval does not overlap with the previous, append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } 
            // Otherwise, there is an overlap, so we merge the current and previous intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};

