class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = 0;
        int alt = 0;

        for(int k: gain){
            alt += k;
            max = max < alt ? alt:max;
        }

        return max;
    }
};