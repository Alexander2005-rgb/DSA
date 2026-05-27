// regular expression matching

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        // dp[i][j] = true if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Empty string matches empty pattern
        dp[0][0] = true;
        
        // Handle patterns like a*, a*b*, a*b*c* matching empty string
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // '*' can match zero or more of the preceding element
                    // Case 1: zero occurrences — skip the preceding char and '*'
                    dp[i][j] = dp[i][j - 2];
                    
                    // Case 2: one or more occurrences — if preceding char matches s[i-1]
                    char preceding = p[j - 2];
                    if (preceding == '.' || preceding == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    // Non-'*' character: must match s[i-1]
                    if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};


int main(){
    Solution s;
    string s;
    cin>>s;
    string p;
    cin>>p;
    cout<<s.isMatch(s,p)<<endl;
    return 0;

}