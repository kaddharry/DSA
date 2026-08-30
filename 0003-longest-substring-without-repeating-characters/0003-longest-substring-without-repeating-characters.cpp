class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,-1);
        int maxl = 0;
        int start = 0;

        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            if(freq[c] >= start){
                start = freq[c]+1;
            }

            freq[c] = i;

            maxl = max(maxl, i - start + 1);
        }
        return maxl;
    }
};