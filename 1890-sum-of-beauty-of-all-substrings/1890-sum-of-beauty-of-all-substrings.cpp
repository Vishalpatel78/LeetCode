class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
    int n = s.size();

    // Iterate over all possible starting points of substrings
    for (int i = 0; i < n; ++i) {
        vector<int> freq(26, 0);  // Frequency array for 26 lowercase letters

        // Generate substrings starting at position i
        for (int j = i; j < n; ++j) {
            freq[s[j] - 'a']++;  // Increment frequency of the current character

            // Find max and min frequencies in the current substring
            int maxFreq = 0, minFreq = n + 1;
            for (int f : freq) {
                if (f > 0) {
                    maxFreq = max(maxFreq, f);
                    minFreq = min(minFreq, f);
                }
            }

            // Calculate beauty for the current substring
            totalBeauty += (maxFreq - minFreq);
        }
    }
    
    return totalBeauty;
        
    }
};