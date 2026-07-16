class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for(int i = s.size()-1; i >=0; i--){
            char c = s[i];
            if(c == ' ' && res > 0) break;
            if(c == ' ') continue;
            else res++;
        }
        return res;
    }
};