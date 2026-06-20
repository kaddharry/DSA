class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int alpha[26] = {0};
        for(char k:s) alpha[k - 'a']++;
        for(char k:t) alpha[k - 'a']--;

        for(int x: alpha){
            if(x) return false;
        }
        return true;
    }
};
        // unordered_map <char, int> mp1;
        // unordered_map <char, int> mp2;
        // for(char k:  s){
        //     mp1[k]++;
        // }
        // for(char c:  t){
        //     mp2[c]++;
        // }
        // if(mp1 == mp2) return true;
        // return false;