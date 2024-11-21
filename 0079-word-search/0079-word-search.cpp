class Solution {
public:
     bool backtrack(vector<vector<char>>& board, string& word, int index, int row, int col) {
        // If index matches the word length, we have found the word
        if (index == word.length()) {
            return true;
        }

        // Check if out of bounds or the character doesn't match
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }

        // Temporarily mark the cell as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore all four directions: up, down, left, right
        bool found = backtrack(board, word, index + 1, row + 1, col) || // Down
                     backtrack(board, word, index + 1, row - 1, col) || // Up
                     backtrack(board, word, index + 1, row, col + 1) || // Right
                     backtrack(board, word, index + 1, row, col - 1);   // Left

        // Restore the cell after exploring
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // Iterate through every cell in the grid
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                // Start the backtracking search if the first letter matches
                if (board[i][j] == word[0] && backtrack(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
