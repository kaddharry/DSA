class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        if(costs[0] > coins) return 0;
        for (int x : costs) {
            if (x > coins)
                break;
            count++;
            coins -= x;
        }
        return count;
    }
};