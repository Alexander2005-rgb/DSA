// jump game 7
//You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

// i + minJump <= j <= min(i + maxJump, s.length - 1), and
// s[j] == '0'.
// Return true if you can reach index s.length - 1 in s, or false otherwise.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] == '1') {
            return false;
        }

        vector<bool> dp(n, false);
        dp[0] = true;

        queue<int> q;
        q.push(0);

        int maxReach = 0; // The farthest index that we have already processed and marked as reachable

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            // Optimization: if we already reached the end, no need to continue
            if (dp[n - 1]) {
                return true;
            }

            // Start searching for reachable '0's from max(i + minJump, maxReach + 1)
            // This avoids re-evaluating positions that have already been covered
            for (int j = max(i + minJump, maxReach + 1); j <= min(i + maxJump, n - 1); ++j) {
                if (s[j] == '0') {
                    dp[j] = true;
                    q.push(j);
                }
            }
            maxReach = min(i + maxJump, n - 1); // Update maxReach to the farthest point covered by current i
        }

        return dp[n - 1];
    }
};

int main(){
    Solution s;
    string s;
    cin>>s;
    int minJump, maxJump;
    cin>>minJump>>maxJump;
    cout<<s.canReach(s, minJump, maxJump);
    return 0;
}   
