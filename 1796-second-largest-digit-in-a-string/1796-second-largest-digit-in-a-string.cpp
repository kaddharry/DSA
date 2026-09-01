class Solution {
public:
    int secondHighest(string s) {
        vector<int> upd;
        for(char x: s){
            if(isdigit(x)){
                upd.push_back(x - '0');
            }
        }
        if(upd.empty()) return -1; // no digit in string

        int first = INT_MIN, sec = INT_MIN;
        for(int num: upd){
            if(first < num){
                sec = first;
                first = num;
            }
            else if(first > num && num > sec){
                sec = num;
            }
        }
        
        return (sec == INT_MIN) ? -1 : sec;
    }
};