class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        // ager length brabr hai to fir mapping kro
        // mapping krne ke lie 2 array bna lenge or s t  ko map kr lenge

        vector<char>s_arr(255,-1);// length 255 hai or sb me -1 dal dia hai 
        vector<char>t_arr(255,-1);

        for(int i=0; i<s.length(); i++){
            char s_char = s[i];
            char t_char = t[i];

            // ab mapping start kro 
            if(s_arr[s_char] == -1 && t_arr[t_char] == -1){
                s_arr[s_char] = t_char;
                t_arr[t_char] = s_char;
            }
            else if(s_arr[s_char] != t_char || t_arr[t_char] != s_char){
                    return false;
            }
        }
        return true;

        
    }
};