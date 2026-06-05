/**
You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2].
 

Example 1:

Input: num1 = 120, num2 = 130

Output: 3

Explanation:

In the range [120, 130]:

120: middle digit 2 is a peak, waviness = 1.
121: middle digit 2 is a peak, waviness = 1.
130: middle digit 3 is a peak, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 2:

Input: num1 = 198, num2 = 202

Output: 3

Explanation:

In the range [198, 202]:

198: middle digit 9 is a peak, waviness = 1.
201: middle digit 0 is a valley, waviness = 1.
202: middle digit 0 is a valley, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 3:

Input: num1 = 4848, num2 = 4848

Output: 2

Explanation:

Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

 

Constraints:

1 <= num1 <= num2 <= 1015​​​​​​​


The solution uses digit DP (dynamic programming) to efficiently compute the total waviness sum across the range [num1, num2].

Key idea: We compute solve(n) = total waviness of all numbers in [0, n], then answer = solve(num2) - solve(num1 - 1).

Digit DP state:

pos — current position in the digit string
tight — whether we're bound by the prefix of n
prev — the last digit placed (10 = none yet)
prevPrev — the second-to-last digit (10 = none yet)
At each step, when placing digit d, we check if the triple (prevPrev, prev, d) forms a peak or valley, contributing 1 to the waviness sum. The DP returns {count, sum} so we can propagate both the number of valid suffixes and the accumulated waviness upward.

The memoization uses O(len * 2 * 11 * 11) states, which is tiny — the time complexity is about O(len * 2 * 11 * 11 * 10), easily handling n up to 10^15 (at most 16 digits).
 */
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }

private:
    string s;

    struct Node {
        long long cnt;
        long long sum;
    };

    Node dp[20][2][11][11][2];
    bool vis[20][2][11][11][2];

    Node dfs(int pos, bool tight, int prev, int prevPrev, bool started) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (vis[pos][tight][prev][prevPrev][started]) {
            return dp[pos][tight][prev][prevPrev][started];
        }

        vis[pos][tight][prev][prevPrev][started] = true;

        int limit = tight ? s[pos] - '0' : 9;

        long long totalCnt = 0;
        long long totalSum = 0;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);

            // Still in leading zeros
            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, newTight, 10, 10, false);
                totalCnt += nxt.cnt;
                totalSum += nxt.sum;
                continue;
            }

            long long add = 0;

            if (started && prevPrev != 10) {
                if ((prev > prevPrev && prev > d) ||
                    (prev < prevPrev && prev < d)) {
                    add = 1;
                }
            }

            int newPrevPrev = started ? prev : 10;
            int newPrev = d;

            Node nxt = dfs(pos + 1, newTight, newPrev, newPrevPrev, true);

            totalCnt += nxt.cnt;
            totalSum += nxt.sum + add * nxt.cnt;
        }

        return dp[pos][tight][prev][prevPrev][started] =
                   {totalCnt, totalSum};
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, true, 10, 10, false).sum;
    }
};


int main(){

    Solution s;
    int num1,num2;
    cin>>num1>>num2;
    cout<<s.totalWaviness(num1,num2)<<endl;
    return 0;

}