class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int m = fb.size();
        if(n == 0) return true;
        for (int i = 0; i < m; i++) {
            if (fb[i] == 0 &&
                (i == 0 || fb[i - 1] == 0) &&
                (i == m - 1 || fb[i + 1] == 0)) {

                fb[i] = 1;
                n--;

                if (n == 0)
                    return true;
            }
        }

        return n == 0;
    }
};