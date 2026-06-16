class Solution {
public:
    string processStr(string s) {
        string result = "";
        
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                // Append lowercase letter
                result += c;
            } else if (c == '*') {
                // Remove last character if it exists
                if (!result.empty()) {
                    result.pop_back();
                }
            } else if (c == '#') {
                // Duplicate current result and append to itself
                result += result;
            } else if (c == '%') {
                // Reverse current result
                reverse(result.begin(), result.end());
            }
        }
        
        return result;
    }
};