// JUMP GAME    5
// IN ONE STEP YOU CAN JUMP INDEX I TO   I+X where i+x < arr.length and 0 <x<=d.
// i-x where i-x>0 
//In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 1);  // dp[i] = max indices visitable starting from i
        
        // Create vector of indices sorted by height (ascending)
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return arr[a] < arr[b];
        });
        
        // Process from shortest to tallest
        for (int idx : indices) {
            int best = 1;
            
            // Try jumping to the left
            for (int j = idx - 1; j >= max(0, idx - d); --j) {
                if (arr[j] >= arr[idx]) break;  // Can't jump over taller/equal element
                best = max(best, 1 + dp[j]);
            }
            
            // Try jumping to the right
            for (int j = idx + 1; j <= min(n - 1, idx + d); ++j) {
                if (arr[j] >= arr[idx]) break;  // Can't jump over taller/equal element
                best = max(best, 1 + dp[j]);
            }
            
            dp[idx] = best;
        }
        
        // Return the maximum dp value across all start indices
        return *max_element(dp.begin(), dp.end());
    }
};

int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
    int d;
    cin>>d;
    cout<<s.maxJumps(arr,d);
    return 0;
}