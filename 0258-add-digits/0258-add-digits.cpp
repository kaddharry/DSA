class Solution {
public:
    int SOD(int num) {
        int res = 0;
        while (num) {
            res = res + num % 10;
            num /= 10;
        }
        return res;
    }
    int addDigits(int num) {
        while (num / 10) {
            num = SOD(num);
        }
        return num;
    }
};