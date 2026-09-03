class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = 0;
        int cost = 0;
        int l = 0;
        for(int i = 0; i < s.size(); ++i){
            char a = s[i];
            char b = t[i];
            cost += abs(a - b);
            while(cost > maxCost && l < i){
                char x = s[l];
                char y = t[l];
                cost -= abs(x - y);
                l++;
            }

            if(cost <= maxCost) len = max(len, i - l +1);
        }
        return len;
    }
};