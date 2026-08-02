class Solution {
public:
    // int MEX(vector<int> vec) {
    //     int mex = 0;
    //     if (vec[0] > 0)
    //         return mex;
    //     unordered_set<int> st(vec.begin(), vec.end());
    //     while (st.count(mex))
    //         mex++;
    //     return mex;
    // }
    int findSmallestInteger(vector<int>& nums, int val) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            int key = (x % val + val) % val;
            mp[key]++;
        }
        int mex = 0;
        while (mp.count(mex % val)) {
            mp[mex % val]--;
            if (mp[mex % val] == 0)
                mp.erase(mex % val);
            mex++;
        }
        return mex;
    }
};