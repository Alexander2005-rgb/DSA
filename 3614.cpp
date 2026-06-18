class Solution {
public:
char processStr(string s, long long k) {
int n = s.size();

    // Store information about the string state after each operation.
    // Each entry: (length_after_op, global_reversed_after_op, appended_char)
    vector<tuple<long long, bool, char>> history;
    
    long long current_len = 0;
    bool current_global_reversed = false;
    
    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            current_len++;
            history.push_back({current_len, current_global_reversed, ch});
        } else if (ch == '*') {
            if (current_len > 0) current_len--;
            history.push_back({current_len, current_global_reversed, ' '});
        } else if (ch == '#') {
            current_len *= 2;
            history.push_back({current_len, current_global_reversed, ' '});
        } else if (ch == '%') {
            current_global_reversed = !current_global_reversed;
            history.push_back({current_len, current_global_reversed, ' '});
        }
    }
    
    if (history.empty()) return '.';
    
    long long final_len = get<0>(history.back());
    if (k >= final_len) return '.';
    
    long long target_k = k;
    bool current_k_is_reversed = false;
    
    for (int i = n - 1; i >= 0; i--) {
        auto& entry = history[i];
        long long len_after_op = get<0>(entry);
        bool global_reversed_after_op = get<1>(entry);
        char appended_char = get<2>(entry);
        
        long long prev_len_for_op = 0;
        if (i > 0) prev_len_for_op = get<0>(history[i - 1]);
        
        if (current_k_is_reversed) {
            target_k = len_after_op - 1 - target_k;
            current_k_is_reversed = false;
        }
        
        char op_char = s[i];
        
        if (op_char >= 'a' && op_char <= 'z') {
            if (target_k == len_after_op - 1) {
                return appended_char;
            }
        } else if (op_char == '*') {
            if (target_k == len_after_op) {
                return '.';
            }
        } else if (op_char == '#') {
            if (target_k >= prev_len_for_op) {
                target_k -= prev_len_for_op;
            }
        } else if (op_char == '%') {
            current_k_is_reversed = true;
        }
        
        if (target_k < 0 || target_k >= prev_len_for_op) {
            return '.';
        }
    }
    
    return '.';
}