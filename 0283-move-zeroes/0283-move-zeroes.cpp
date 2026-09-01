class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int p = 0;
        int counter = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[p] = nums[i];
                p++;
            }
            else counter++;
        }
        p = nums.size()-1;
        while(counter){
            nums[p] = 0;
            counter--;
            p--;
        }
    }
};