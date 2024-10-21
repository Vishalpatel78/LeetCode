 

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (depth > 0) {
                    result += c; // Only add if it's not an outermost '('
                }
                depth++;
            } else {
                depth--;
                if (depth > 0) {
                    result += c; // Only add if it's not an outermost ')'
                }
            }
        }
        
        return result;
    }
};