class Solution {
public:
    string longestPalindrome(string s) {
          int n = s.size();
    if (n < 2) return s;  // If the string is empty or has only one character, it's the longest palindrome itself.

    int start = 0, maxLength = 1;

    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;  // Length of the palindrome
    };

    for (int i = 0; i < n; i++) {
        // Expand around center for odd-length palindrome
        int len1 = expandAroundCenter(i, i);
        // Expand around center for even-length palindrome
        int len2 = expandAroundCenter(i, i + 1);

        int len = max(len1, len2);

        // Update the longest palindrome found
        if (len > maxLength) {
            maxLength = len;
            start = i - (len - 1) / 2;
        }
    }

    return s.substr(start, maxLength);

        
    }
};