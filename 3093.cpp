//Longest Common Suffix Queries

// You are given two arrays of strings wordsContainer and wordsQuery.

// For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.

// Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].



// Constraints:

// 1 <= wordsContainer.length, wordsQuery.length <= 104
// 1 <= wordsContainer[i].length <= 5 * 103
// 1 <= wordsQuery[i].length <= 5 * 103
// wordsContainer[i] consists only of lowercase English letters.
// wordsQuery[i] consists only of lowercase English letters.
// Sum of wordsContainer[i].length is at most 5 * 105.
// Sum of wordsQuery[i].length is at most 5 * 105.


/**
by oberving ans anylysing this problem first we think about how we can store the suffixes of the words in a data structure and then query for the longest common suffix 
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Trie node structure
        struct TrieNode {
            // child nodes for 'a' to 'z'
            TrieNode* children[26] = {nullptr};
            // best index in wordsContainer for this node (suffix ending here)
            int bestIdx = -1;
        };
        
        // Helper: compare two indices and return the better one based on:
        // 1. shorter length -> better
        // 2. if same length, earlier index -> better
        auto better = [&](int a, int b) -> int {
            if (a == -1) return b;
            if (b == -1) return a;
            int lenA = wordsContainer[a].length();
            int lenB = wordsContainer[b].length();
            if (lenA != lenB) return lenA < lenB ? a : b;
            return a < b ? a : b;
        };
        
        TrieNode* root = new TrieNode();
        
        // Insert all words from wordsContainer into the trie (reversed)
        for (int i = 0; i < wordsContainer.size(); i++) {
            const string& w = wordsContainer[i];
            TrieNode* cur = root;
            // Also update the root: empty suffix matches everything
            root->bestIdx = better(root->bestIdx, i);
            
            // Insert character by character (reversed order)
            for (int j = w.length() - 1; j >= 0; j--) {
                int c = w[j] - 'a';
                if (cur->children[c] == nullptr) {
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
                cur->bestIdx = better(cur->bestIdx, i);
            }
        }
        
        // Answer each query
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& q : wordsQuery) {
            TrieNode* cur = root;
            int resultIdx = root->bestIdx; // at minimum, empty suffix match
            
            // Traverse the query string from the end
            for (int j = q.length() - 1; j >= 0; j--) {
                int c = q[j] - 'a';
                if (cur->children[c] == nullptr) {
                    break; // no further suffix match
                }
                cur = cur->children[c];
                resultIdx = cur->bestIdx;
            }
            
            ans.push_back(resultIdx);
        }
        
        return ans;
    }
};


// for this problem we use the trie data structure and method of compressed trie 
// trie means tree like data structure where each node represents a character
// compressed trie is a trie data structure in which we store the best index of the suffix
// Time complexity: O(N*L + M*L)
// Space complexity: O(N*L)
class Solution1 {
public:
    // Using a struct with primitive types/arrays to minimize memory overhead
    struct TrieNode {
        int children[26];
        int bestIdx = -1;
    };

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // A flat vector to hold all trie nodes sequentially in memory
        vector<TrieNode> trie;
        
        // Initialize the root node at index 0
        trie.push_back(TrieNode());
        memset(trie[0].children, -1, sizeof(trie[0].children));
        
        // Lambda to determine which index is better based on the rules:
        // 1. Shorter length is better
        // 2. Tie-breaker: Earlier index in wordsContainer is better
        auto better = [&](int a, int b) -> int {
            if (a == -1) return b;
            if (b == -1) return a;
            if (wordsContainer[a].length() != wordsContainer[b].length()) {
                return wordsContainer[a].length() < wordsContainer[b].length() ? a : b;
            }
            return a < b ? a : b;
        };
        
        // Build the Suffix Trie
        for (int i = 0; i < wordsContainer.size(); i++) {
            const string& w = wordsContainer[i];
            int cur = 0; // Start at the root node (index 0)
            
            // Update the root node's bestIdx (for the empty suffix match)
            trie[0].bestIdx = better(trie[0].bestIdx, i);
            
            // Insert the string backwards to index its suffixes
            for (int j = w.length() - 1; j >= 0; j--) {
                int c = w[j] - 'a';
                if (trie[cur].children[c] == -1) {
                    // Create a new node by pushing it to the vector
                    trie[cur].children[c] = trie.size();
                    TrieNode newNode;
                    memset(newNode.children, -1, sizeof(newNode.children));
                    trie.push_back(newNode);
                }
                cur = trie[cur].children[c];
                // Update the best index available at this prefix path
                trie[cur].bestIdx = better(trie[cur].bestIdx, i);
            }
        }
        
        // Answer each query
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& q : wordsQuery) {
            int cur = 0;
            int resultIdx = trie[0].bestIdx; // Default to best overall if no suffix matches
            
            // Traverse the query string backwards
            for (int j = q.length() - 1; j >= 0; j--) {
                int c = q[j] - 'a';
                if (trie[cur].children[c] == -1) {
                    break; // Suffix match ends here
                }
                cur = trie[cur].children[c];
                resultIdx = trie[cur].bestIdx;
            }
            ans.push_back(resultIdx);
        }
        
        return ans;
    }
};


int main(){
    Solution1 s;
    vector<string> wordsContainer = {"abcd", "bcab", "baba"};
    vector<string> wordsQuery = {"abab", "baba", "abcd", "bcab"};
    vector<int> ans = s.stringIndices(wordsContainer, wordsQuery);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;

}
