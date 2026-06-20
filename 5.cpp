//longest palindrome substring in a given string



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int n = s.length();
        // dp[i][j] will be true if the substring s[i..j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0; // Starting index of the longest palindromic substring
        int maxLength = 1; // Length of the longest palindromic substring

        // All single characters are palindromes
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // Check for palindromes of length 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for palindromes of length greater than 2
        // k is the length of the substring
        for (int k = 3; k <= n; ++k) {
            // i is the starting index
            for (int i = 0; i <= n - k; ++i) {
                // j is the ending index
                int j = i + k - 1;

                // If the inner substring is a palindrome and the outer characters match
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (k > maxLength) {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};

// using two pointer method
class Solution1 {
public:
    int start = 0;
    int maxLen = 1;

    void expandFromCenter(string &s, int left, int right) {
        while (left >= 0 && right < s.length() &&
               s[left] == s[right]) {
            left--;
            right++;
        }

        // this is the formula for length of the palindrome
        int len = right - left - 1;

        // check if the current palindrome is the longest one
        if (len > maxLen) {
            maxLen = len;
            start = left + 1;
        }
    }

    string longestPalindrome(string s) {
        int n = s.length();

        if (n == 0)
            return "";

        for (int i = 0; i < n; i++) {

            // Odd length palindrome
            expandFromCenter(s, i, i);

            // Even length palindrome
            expandFromCenter(s, i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};


int main() {
    Solution1 sol;
    cout << sol.longestPalindrome("babad") << endl; // Output: bab (or aba)
    cout << sol.longestPalindrome("cbbd") << endl;  // Output: bb
    cout << sol.longestPalindrome("a") << endl;     // Output: a
    cout << sol.longestPalindrome("ac") << endl;     // Output: a (or c)
    return 0;
}