// generate parenthesis 
// constrints  1<= n <= 8
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<string>& result, string current_string, int open, int close) {
        // Base case: If no parentheses are left to add, we found a valid combination
        if (open == 0 && close == 0) {
            result.push_back(current_string);
            return;
        }
        
        // Rule 1: We can always add an opening parenthesis if we have any left
        if (open > 0) {
            backtrack(result, current_string + '(', open - 1, close);
        }
        
        // Rule 2: We can only add a closing parenthesis if it matches an open one
        if (close > open) {
            backtrack(result, current_string + ')', open, close - 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        // Start with an empty string, and 'n' available open and close brackets
        backtrack(result, "", n, n);
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cin>>n;
    vector<string> result = sol.generateParenthesis(n);
    for(string s : result){
        cout<<s<<endl;
    }
    return 0;
}