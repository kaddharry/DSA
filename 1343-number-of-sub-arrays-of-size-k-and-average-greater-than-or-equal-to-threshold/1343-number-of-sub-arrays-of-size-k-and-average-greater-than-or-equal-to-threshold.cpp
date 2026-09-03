class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        double thresh = threshold * k;
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        int res = 0;
        if(sum >= thresh) res++;
        int l = 0;
        for(int i = k; i < nums.size(); ++i){
            sum = sum - nums[l] + nums[i];
            if(sum >= thresh) res++;
            l++;
        }
        return res;
    }
};