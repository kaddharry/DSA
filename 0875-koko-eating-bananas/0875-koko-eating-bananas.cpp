class Solution {
public:
    long long check(vector<int> p, int m) {
        long long sum = 0;
        for (int x : p) {
            sum += ceil((double)x / m);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = INT_MIN;
        for (int x : piles) {
            high = x > high ? x : high;
        }
        int n = piles.size();
        if (low == high)
            return ceil(double(n * low) / h);
        while (low < high) {
            long long mid = (low + high) / 2;
            if (check(piles, mid) > h)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};