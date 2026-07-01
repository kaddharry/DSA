class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        int start = 0, end = 0;
        for(; end < k; end++){
            sum += nums[end];
        }
        double window = sum;
        //we got the initial sum now sliding window part
        for(int i = end; i < nums.size(); i++){
            double temp = window;
            temp += nums[i] - nums[start];
            sum = max(sum,temp);
            window = temp;
            start++;
        }
        return (sum/k);
    }
};