// class Solution {
// public:

//     void remove(string &s, string &part){
//         int find = s.find(part);
//         if(find != string::npos){
//             string left = s.substr(0,find);
//             string right = s.substr(find + part.size(),s.size());
//             s = left + right;

//             remove(s,part);
//         }
//         else{
//             return;
//         }
//     }
//         string removeOccurrences(string s, string part) {
//         remove(s,part);
//         return s;
        
//     }
// };
 




class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t pos = s.find(part);
        size_t part_length = part.length();
        while (pos != string::npos) {
            s.erase(pos, part_length);
            pos = s.find(part); // Find the next occurrence starting from the current position
        }
        return s;
    }
};