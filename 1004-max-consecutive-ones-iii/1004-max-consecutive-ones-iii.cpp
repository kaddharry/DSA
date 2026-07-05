class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
        int l = 0;
        int maxlen = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 0){
                q.push(r);
                if(q.size()>k){
                    l = q.front() + 1;
                    q.pop();
                }
            }
            maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};