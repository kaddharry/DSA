class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> mp;
        vector<int> maxi(n, -1);
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < n && nums2[j] < nums2[i]) {
                if (maxi[j] == -1) {
                    j = n;
                    break;
                }
                j++;
            }
            if (j < n)
                maxi[i] = nums2[j];
        }
        for(int x = 0; x < n; x++){
            mp[nums2[x]] = x;
        }
        vector<int> res;
        for(int x: nums1){
            int i = mp[x];
            res.push_back(maxi[i]);
        }
        return res;
    }
};