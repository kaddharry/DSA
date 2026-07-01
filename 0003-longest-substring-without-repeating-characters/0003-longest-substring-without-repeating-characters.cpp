class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1) return 1;
        int l = 0;
        int left = 0;
        unordered_map <char, int> mp;
        for(int right = 0; right < s.size(); right++){
            char ch = s[right];
            if(!mp.count(ch)) mp[ch] = 1;
            else{
                int temp = mp.size();
                l = max(l,temp);
                while(mp.count(ch)){
                    mp.erase(s[left]);
                    left++;
                }
                mp[ch] = 1;
            }
        }
        if(mp.size()!= 0){
            int n = mp.size();
            l = max(l,n);
        }
        return l;
    }
};