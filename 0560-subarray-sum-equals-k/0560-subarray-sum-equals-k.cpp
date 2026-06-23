class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Map to store frequency of prefix sums
        unordered_map<int, int> prefix_counts;

        // Base case: A prefix sum of 0 has occurred once (before any elements)
        prefix_counts[0] = 1;

        int current_prefix_sum = 0;
        int total_subarrays = 0;

        for (int num : nums) {
            // Update the running prefix sum
            current_prefix_sum += num;

            // Check if (current_prefix_sum - k) exists in our map
            int target_needed = current_prefix_sum - k;
            if (prefix_counts.find(target_needed) != prefix_counts.end()) {
                total_subarrays += prefix_counts[target_needed];
            }

            // Record the current prefix sum into the map
            prefix_counts[current_prefix_sum]++;
        }

        return total_subarrays;
    }
};