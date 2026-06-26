// count the number of special character 2
//You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

// Return the number of special letters in word.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        // Vectors initialized to -1 to signify the character hasn't been seen yet
        std::vector<int> last_lower(26, -1);
        std::vector<int> first_upper(26, -1);
        
        // Populate the tracking arrays
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') {
                last_lower[c - 'a'] = i; // Continually overwrite to get the LAST occurrence
            } else if (c >= 'A' && c <= 'Z') {
                int idx = c - 'A';
                if (first_upper[idx] == -1) {
                    first_upper[idx] = i; // Only record the FIRST occurrence
                }
            }
        }
        
        int special_count = 0;
        
        // Count how many character pairs fulfill the "special" conditions
        for (int i = 0; i < 26; ++i) {
            if (last_lower[i] != -1 && first_upper[i] != -1) {
                if (last_lower[i] < first_upper[i]) {
                    special_count++;
                }
            }
        }
        
        return special_count;
    }
};



int main(){
    Solution s;
    string word = "aaB";
    cout << s.numberOfSpecialChars(word) << endl;
    return 0;
}