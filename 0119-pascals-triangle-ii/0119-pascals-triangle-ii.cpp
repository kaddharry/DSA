class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i = 0; i <= rowIndex; i++){
            vector<int> currRow(i+1,1);
            for(int j = 1; j < i; j++){
                currRow[j] = res[j-1] + res[j];
            }
            res = currRow;
        }
        return res;
    }
};