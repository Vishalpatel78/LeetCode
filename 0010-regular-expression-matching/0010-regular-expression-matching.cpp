class Solution {
public:
    bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();

    // Create a DP table
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Base case: both string and pattern are empty
    dp[0][0] = true;

    // Handle patterns with '*' that can match zero preceding elements
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                // Characters match or '.' matches any character
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                // '*' can either match zero or more of the preceding element
                dp[i][j] = dp[i][j - 2] || 
                          ((p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j]);
            }
        }
    }

    return dp[m][n];
}
};