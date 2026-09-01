class Solution {
public:
    int secondHighest(string s) {
        int first = INT_MIN, sec = INT_MIN;

        for (char x : s) {
            if (isdigit(x)) {
                int num = x - '0'; // Convert on the fly
                
                if (num > first) {
                    sec = first;
                    first = num;
                } else if (num < first && num > sec) {
                    sec = num;
                }
            }
        }
        
        return (sec == INT_MIN) ? -1 : sec;
    }
};
