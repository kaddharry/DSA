class Solution {
public:
    int longestPalindrome(string s) {
        if(s == "") return 0;
        int flag = 0;
        int length = 0;
        unordered_map<char, int> mp;

        for(char c: s){
            mp[c]++;
        }
        for(auto it: mp){
            int key = it.first;
            int val = it.second;

            if(val % 2 == 1){
                mp[key]--;
                flag++;
            }

            length += mp[key];
        }
        if(flag > 0) length++;

        return length;
    }
};