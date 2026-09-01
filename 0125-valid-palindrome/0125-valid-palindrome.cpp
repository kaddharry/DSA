class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j){
            char a = tolower(s[i]);
            char b = tolower(s[j]);
            if(isalnum(a) && isalnum(b)){
                if(a != b) return false;
                i++;
                j--;
            }
            else{
                if(!isalnum(a)) i++;
                if(!isalnum(b)) j--;
            }
        }
        return true;
    }
};