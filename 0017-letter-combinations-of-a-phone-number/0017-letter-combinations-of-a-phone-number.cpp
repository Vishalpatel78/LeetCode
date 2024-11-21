class Solution {
public:
   vector<string> letterCombinations(string digits) {
        // Define the mapping of digits to letters
        unordered_map<char, string> digit_to_letters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        
        vector<string> result;
        
        // Base case: if digits is empty, return an empty result
        if (digits.empty()) {
            return result;
        }
        
        // Helper function for backtracking
        backtrack(digits, 0, "", result, digit_to_letters);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string current, vector<string>& result, unordered_map<char, string>& digit_to_letters) {
        // If the current combination is of the same length as digits, add it to result
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        // Get the letters corresponding to the current digit
        string letters = digit_to_letters[digits[index]];
        
        // Recurse for each letter corresponding to the current digit
        for (char letter : letters) {
            backtrack(digits, index + 1, current + letter, result, digit_to_letters);
        }
    }
};