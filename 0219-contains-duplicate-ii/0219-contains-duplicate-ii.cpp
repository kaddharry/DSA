class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = min(k + 1, n);

        unordered_set<int> st;

        for (int i = 0; i < windowSize; i++) {
            if (st.count(nums[i]))
                return true;
            st.insert(nums[i]);
        }

        int l = 0;
        int r = windowSize;

        while (r < n) {
            st.erase(nums[l]);
            st.insert(nums[r]);

            l++;
            r++;

            if (st.size() < windowSize)
                return true;
        }

        return false;
    }
};