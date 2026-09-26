class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_all = 0;
        for(int i : nums){
            xor_all ^= i;
        }
        long long mask = xor_all & -xor_all;
        int first = 0;
        int second = 0;
        for (int x : nums) {
            if (x & mask)
                first ^= x;
            else
                second ^= x;
        }
        return {first, second};
    }
};

/*
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // long long xor_all = nums[0];
        long long xor_all = 0;
        for(int i : nums){
            xor_all ^= i;
        }
        long long mask = xor_all & -xor_all;
        int first = 0;
        int second = 0;
        for(int x: nums){
            if(first & mask) first ^= mask;
            else second ^= mask;
        }
        return {first, second};
    }
};
*/