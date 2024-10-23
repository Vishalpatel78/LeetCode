class Solution {
public:
    bool rotateString(string s, string goal) {
        // If the lengths of s and goal are not equal, they can't be rotations of each other
        if(s.length() != goal.length()) return false;

        // Concatenate s with itself to account for all possible rotations
        string ss = s + s;

        // Check if goal is a substring of ss
        if(ss.find(goal) != string::npos) {
            return true;
        } else {
            return false;
        }
    }
};
