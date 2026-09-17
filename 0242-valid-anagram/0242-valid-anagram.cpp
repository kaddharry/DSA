class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int alpha[26] = {0};
        for(char x: s) alpha[x - 'a']++;
        for(char x: t) alpha[x - 'a']--;

        for(int x: alpha){
            if(x) return false;
        }
        return true;
    }
};