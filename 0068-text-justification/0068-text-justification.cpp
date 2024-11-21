class Solution {
public:
 
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            // Step 1: Add words until the line exceeds maxWidth
            int lineLength = words[i].size();
            int j = i + 1;
            while (j < n && lineLength + words[j].size() + (j - i - 1) < maxWidth) {
                lineLength += words[j].size();
                j++;
            }

            // Step 2: Create the current line
            int numWordsInLine = j - i;
            int totalSpaces = maxWidth - lineLength;

            // If it's the last line or the line has only one word
            if (j == n || numWordsInLine == 1) {
                string line = words[i];
                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }
                line += string(maxWidth - line.size(), ' ');  // Add remaining spaces
                result.push_back(line);
            } else {
                // Distribute spaces evenly
                int spacesBetweenWords = totalSpaces / (numWordsInLine - 1);
                int extraSpaces = totalSpaces % (numWordsInLine - 1);

                string line = words[i];
                for (int k = i + 1; k < j; k++) {
                    int spaces = spacesBetweenWords + (k - i <= extraSpaces ? 1 : 0);
                    line += string(spaces, ' ') + words[k];
                }
                result.push_back(line);
            }

            // Step 3: Move to the next set of words
            i = j;
        }

        return result;
    }
};