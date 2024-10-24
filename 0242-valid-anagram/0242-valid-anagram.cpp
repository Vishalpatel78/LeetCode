 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;  // Step 1: Check length
        
        unordered_map<char, int> freq;  // Step 2: Frequency map
        
        // Count frequencies of characters in string s
        for (char c : s) {
            freq[c]++;
        }
        
        // Decrease frequencies for characters in string t
        for (char c : t) {
            freq[c]--;
        }
        
        // Step 3: Check if all frequencies are 0
        for (auto count : freq) {
            if (count.second != 0) {
                return false;  // If any frequency is not zero, it's not an anagram
            }
        }
        
        return true;  // If all frequencies match, it's an anagram
    }
};

