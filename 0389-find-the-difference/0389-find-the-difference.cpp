class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[26] = {0};
        for(char c: s){
            freq[c - 'a']++;
        }
        char result;
        for(char c: t){
            freq[c - 'a']--;
            if(freq[c - 'a'] < 0){
                result = c;
                break;
            } 
        }
        return result;

    }
};