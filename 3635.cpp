// earliest finish time for land and water rides 2

/**
You are given two categories of theme park attractions: land rides and water rides.

Land rides
landStartTime[i] – the earliest time the ith land ride can be boarded.
landDuration[i] – how long the ith land ride lasts.
Water rides
waterStartTime[j] – the earliest time the jth water ride can be boarded.
waterDuration[j] – how long the jth water ride lasts.
A tourist must experience exactly one ride from each category, in either order.

A ride may be started at its opening time or any later moment.
If a ride is started at time t, it finishes at time t + duration.
Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
Return the earliest possible time at which the tourist can finish both rides.

Constraints:

1 <= n, m <= 5 * 104
landStartTime.length == landDuration.length == n
waterStartTime.length == waterDuration.length == m
1 <= landStartTime[i], landDuration[i], waterStartTime[j], waterDuration[j] <= 105

 */

 #include<bits/stdc++.h>
 using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        // Pair water rides and sort by start time
        vector<pair<int, int>> water;
        for (int j = 0; j < m; ++j) {
            water.emplace_back(waterStartTime[j], waterDuration[j]);
        }
        sort(water.begin(), water.end());
        
        // Suffix minima for (start + duration) for water rides
        vector<long long> suffStartPlusDur(m + 1, LLONG_MAX);
        for (int j = m - 1; j >= 0; --j) {
            long long start = water[j].first;
            long long dur = water[j].second;
            suffStartPlusDur[j] = min(suffStartPlusDur[j + 1], start + dur);
        }
        
        // Prefix minima of duration for water rides
        vector<long long> prefDur(m + 1, LLONG_MAX);
        for (int j = 0; j < m; ++j) {
            prefDur[j + 1] = min(prefDur[j], (long long)water[j].second);
        }
        
        long long ans = LLONG_MAX;
        
        // --- Case 1: Land first, then water ---
        // finish = max(waterStart[j], landFinish) + waterDuration[j]
        // landFinish = landStart[i] + landDuration[i]
        // If waterStart[j] < landFinish: finish = landFinish + waterDuration[j]
        // If waterStart[j] >= landFinish: finish = waterStart[j] + waterDuration[j]
        for (int i = 0; i < n; ++i) {
            long long landFinish = (long long)landStartTime[i] + landDuration[i];
            
            // First water ride with start >= landFinish
            int idx = lower_bound(water.begin(), water.end(), 
                                  make_pair((int)min(landFinish, (long long)INT_MAX), 0))
                      - water.begin();
            
            if (idx > 0) {
                ans = min(ans, landFinish + prefDur[idx]);
            }
            if (idx < m) {
                ans = min(ans, suffStartPlusDur[idx]);
            }
            // Also consider: what if we wait to start the land ride later?
            // No, starting later never helps for land-first since it only pushes everything back.
        }
        
        // --- Case 2: Water first, then land ---
        // Pair land rides and sort by start time
        vector<pair<int, int>> land;
        for (int i = 0; i < n; ++i) {
            land.emplace_back(landStartTime[i], landDuration[i]);
        }
        sort(land.begin(), land.end());
        
        // Suffix minima of (start + duration) for land rides
        vector<long long> landSuffStartPlusDur(n + 1, LLONG_MAX);
        for (int i = n - 1; i >= 0; --i) {
            long long start = land[i].first;
            long long dur = land[i].second;
            landSuffStartPlusDur[i] = min(landSuffStartPlusDur[i + 1], start + dur);
        }
        
        // Prefix minima of duration for land rides
        vector<long long> landPrefDur(n + 1, LLONG_MAX);
        for (int i = 0; i < n; ++i) {
            landPrefDur[i + 1] = min(landPrefDur[i], (long long)land[i].second);
        }
        
        for (int j = 0; j < m; ++j) {
            long long waterFinish = (long long)waterStartTime[j] + waterDuration[j];
            
            int idx = lower_bound(land.begin(), land.end(), 
                                  make_pair((int)min(waterFinish, (long long)INT_MAX), 0))
                      - land.begin();
            
            if (idx > 0) {
                ans = min(ans, waterFinish + landPrefDur[idx]);
            }
            if (idx < n) {
                ans = min(ans, landSuffStartPlusDur[idx]);
            }
        }
        
        return (int)ans;
    }
};



int main(){
    Solution s;
    vector<int> landStartTime = {1, 3, 5};
    vector<int> landDuration = {2, 4, 6};
    vector<int> waterStartTime = {2, 4, 6};
    vector<int> waterDuration = {1, 3, 5};
    cout << s.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << endl;
    return 0;
}   