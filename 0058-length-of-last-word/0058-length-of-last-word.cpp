class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int res = 0;
        for(char c: s){
            if(c == ' '){
                if(len) res = len;
                len = 0;
            }
            else len++;
        }
        if(len) res = len;
        return res;
    }
};