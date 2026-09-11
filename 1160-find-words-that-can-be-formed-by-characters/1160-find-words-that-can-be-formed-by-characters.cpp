class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26,0);
        for(char c: chars){
            freq[c - 'a']++;
        }
        int res = 0;
        for(string s: words){
            vector<int> temp = freq;
            int len = 0;
            for(char c: s){
                if(temp[c - 'a'] == 0){
                    len = 0;
                    break;
                }
                temp[c - 'a']--;
                len++;
            }
            res += len;
        }
        return res;
    }
};