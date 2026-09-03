class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int m) {
        int res = 0;
        for(int i = 0; i < grumpy.size(); i++){
            if(grumpy[i] == 0) res += customers[i];
        }
        //now res holds number of satisfied customers
        int extra = 0;
        for(int i = 0; i < m; ++i){
            if(grumpy[i] == 1) extra += customers[i];
        }
        int l = 0;
        int temp = extra;
        for(int i = m; i< grumpy.size(); ++i){
            if(grumpy[l] == 1) temp -= customers[l];
            l++;
            if(grumpy[i] == 1) temp += customers[i];
            extra = max(extra, temp);
        }
        return res+extra;
    }
};