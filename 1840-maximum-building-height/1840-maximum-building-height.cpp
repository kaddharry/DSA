class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rest) {
        rest.push_back({1, 0});
        rest.push_back({n, n - 1});
        sort(rest.begin(), rest.end());

        int m = rest.size();

        for (int i = 1; i < m; i++)
            rest[i][1] = min(rest[i][1], rest[i-1][1] + (rest[i][0] - rest[i-1][0]));

        for (int i = m - 2; i >= 0; i--)
            rest[i][1] = min(rest[i][1], rest[i+1][1] + (rest[i+1][0] - rest[i][0]));

        int ans = 0;
        for (int i = 1; i < m; i++) {
            int x1 = rest[i-1][0], h1 = rest[i-1][1];
            int x2 = rest[i][0],   h2 = rest[i][1];
            ans = max(ans, (x2 - x1 + h1 + h2) / 2);
        }

        return ans;
    }
};