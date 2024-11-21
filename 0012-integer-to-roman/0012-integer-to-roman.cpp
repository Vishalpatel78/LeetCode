class Solution {
public:
      string intToRoman(int num) {
        // Define the Roman numeral values and their corresponding symbols
        vector<pair<int, string>> roman_values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";
        
        // Traverse through the roman_values and subtract the value from num
        for (auto& pair : roman_values) {
            while (num >= pair.first) {
                result += pair.second;  // Add the Roman symbol to result
                num -= pair.first;      // Subtract the value
            }
        }
        
        return result;
    }
};