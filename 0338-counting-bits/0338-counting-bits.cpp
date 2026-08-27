class Solution {
public:
    int noo(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        int res = 0;
        while(n != 0){
            n = n & (n-1);
            res++;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0; i <= n; i++){
            int k = noo(i);
            result.push_back(k);
        }
        return result;
    }
};