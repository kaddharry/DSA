class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int pos = j;

        vector<int> ans(nums.size());

        while (pos >= 0) {
            if (abs(nums[j]) > abs(nums[i])) {
                ans[pos] = nums[j] * nums[j];
                j--;
            } else {
                ans[pos] = nums[i] * nums[i];
                i++;
            }
            pos--;
        }

        return ans;
    }
};