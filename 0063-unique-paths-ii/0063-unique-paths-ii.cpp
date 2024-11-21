class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // Initialize a dp array with the same dimensions as obstacleGrid
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // If the starting point is not an obstacle, set dp[0][0] to 1
        if (obstacleGrid[0][0] == 0) {
            dp[0][0] = 1;
        }

        // Fill the first column (if no obstacles)
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i-1][0];
            }
        }

        // Fill the first row (if no obstacles)
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j-1];
            }
        }

        // Fill the rest of the dp array
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) { // No obstacle
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        // Return the value in the bottom-right corner
        return dp[m-1][n-1];
    }
};