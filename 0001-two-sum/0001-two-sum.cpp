class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // using hashmap!
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.count(complement)) {
                return {i, mp[complement]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
// sort(nums.begin(), nums.end()); //wont work because sorting changes the
// postition of numbers int left = 0; int right = nums.size()-1;

// while(left < right){
//     int sum = nums[left] + nums[right];
//     if(sum == target){
//         break;
//     }
//     else if(sum < target)
//         left++;
//     else right--;
// }

// return {left, right};