class Solution {
public:
    string largestOddNumber(string num) {
    int n = num.length();

    // Traverse backwards to find the first odd digit
    for (int i = n - 1; i >= 0; i--) {
        if ((num[i] - '0') % 2 != 0) {
            return num.substr(0, i + 1);  // Return substring from start to this odd digit
        }
    }

    // If no odd number is found, return an empty string
    return "";
}

};
