// letter combination of a phone number

// constraint 1<= digit.length <= 4 , digit[i] is a digit in the range ['2','9'] 


#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    // Mapping of phone digits to their corresponding letters
    const vector<string> mapping = {
        "",     "",     "abc",  "def", 
        "ghi",  "jkl",  "mno",  "pqrs", 
        "tuv",  "wxyz"
    };

    void backtrack(const string& digits, int index, string& current, vector<string>& result) {
        // Base Case: If the current combination's length matches the input digits length
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the letters corresponding to the current digit
        string letters = mapping[digits[index] - '0'];
        
        // Loop through the letters and recurse
        for (char letter : letters) {
            current.push_back(letter);             // Choose
            backtrack(digits, index + 1, current, result); // Recurse
            current.pop_back();                    // Backtrack (Undo choice)
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        // Edge case: if the input is empty, return an empty list
        if (digits.empty()) {
            return result;
        }
        
        string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
};

