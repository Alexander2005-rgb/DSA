// longest substring without repeating character
/**
Given a string s, find the length of the longest substring without repeating characters.

Examples:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.


*/

#include<bits/stdc++.h>
using namespace std;
// optimal solution  sliding window + hash set
class Solution{
    public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxLen = 0;
        int left = 0;
        unordered_set<char> set;// use unordered set because we need to check the presence of character in the set which take constant time
        for(int right = 0; right < n; right++)
        {
            while(set.count(s[right]))
            {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

// better approch using hash map

class Solution1{
    public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxLen = 0;
        int left = 0;
        unordered_map<char, int> map;
        for(int right = 0; right < n; right++)
        {
            if(map.find(s[right]) != map.end())
            {
                left = max(left, map[s[right]] + 1);
            }
            map[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
}
int main()
{
    Solution s;
    string str;
    cin >> str;
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}
