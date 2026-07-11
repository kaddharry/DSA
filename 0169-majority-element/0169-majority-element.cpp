class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element;

        for(int x : nums) {
            if(count == 0)
                element = x;
            if(x == element)
                count++;
            else
                count--;
        }
        return element;   
    }
};