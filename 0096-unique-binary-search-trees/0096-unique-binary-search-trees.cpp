class Solution {
public:
    int helper(int n, vector<int> &dp){
        if(n == 0)return 1;
        if(n == 1)return 1;

        if(dp[n] != -1){
            return dp[n];
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            int left = helper(i-1, dp);
            int right = helper(n-i, dp);

            ans += left * right;
        }
        dp[n] = ans;
        return ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};