class Solution {
public:
    string reverseWords(string s) {
        string result, word;
        int n = s.length();
        int i = 0;

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // Step 2: Traverse the string and reverse the words
        while (i < n) {
            // Extract words separated by spaces
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Add the word to the result in reverse order
            if (!word.empty()) {
                if (!result.empty()) result = word + " " + result;
                else result = word;
            }
            word.clear(); // Clear the word for next iteration

            // Skip multiple spaces
            while (i < n && s[i] == ' ') i++;
        }

        return result;
    }
};
