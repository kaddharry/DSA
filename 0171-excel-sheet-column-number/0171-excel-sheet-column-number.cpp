class Solution {
public:
    int titleToNumber(string columnTitle) {
        // ascii value - 64 equals the position value of the number
        int i = columnTitle.size()-1;
        int res = 0;

        for(char c: columnTitle){
            res += ((int)c - 64)*pow(26,i);
            i--;
        }
        return res;
    }
};