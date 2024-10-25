class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, result = 0;
    int n = s.size();

     
    while (i < n && s[i] == ' ') {
        i++;
    }

    
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
 
    while (i < n && isdigit(s[i])) {
        int digit = s[i] - '0';
 
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

   
    return result * sign;
}
        
    
};