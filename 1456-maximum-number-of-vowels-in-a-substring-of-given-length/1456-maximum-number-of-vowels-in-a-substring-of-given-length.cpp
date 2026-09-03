class Solution {
public:
    bool check(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int count = 0;
        for(int i = 0; i < k; i++){
            char c = s[i];
            if(check(c)){
                count++;
            }
            if(count == k) return count;
        }
        int l = 0;
        int res = count;
        for(int i = k; i < s.size(); i++){
            char c = s[i];
            char rem = s[l]; //remove character

            if(check(c)) count++;
            if(check(rem)) count--;
            l++;

            res = max(res, count);
            if(res == k) return res;
        }
        return res;
    }
};