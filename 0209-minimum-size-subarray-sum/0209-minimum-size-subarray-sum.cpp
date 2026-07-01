class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlength = INT_MAX;
        int sum = 0;
        int start = 0, end = 0;

        while (end < nums.size()) {
            sum += nums[end];
            end++;

            while (sum >= target) {
                minlength = min(minlength, end - start);
                sum -= nums[start];
                start++;
            }
        }

        return (minlength == INT_MAX) ? 0 : minlength;
    }
};