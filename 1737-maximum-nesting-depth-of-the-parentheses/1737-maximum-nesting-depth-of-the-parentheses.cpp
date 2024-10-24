class Solution {
public:
    int maxDepth(string s) {
         int currentDepth = 0, maxDepth = 0;

    for (char c : s) {
        if (c == '(') {
            currentDepth++;  // Increase depth for open parenthesis
            maxDepth = max(maxDepth, currentDepth);  // Update max depth if needed
        } else if (c == ')') {
            currentDepth--;  // Decrease depth for close parenthesis
        }
    }

    return maxDepth;
    }
};