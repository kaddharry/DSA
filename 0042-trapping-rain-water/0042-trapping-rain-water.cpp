
class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        if (n <= 2) { // Cannot trap water with 0, 1, or 2 bars
            return 0;
        }

        int left = 0;
        int right = n - 1;
        int left_max = 0;
        int right_max = 0;
        int total_water = 0;

        while (left <= right) {
            // When height[left] is smaller than height[right],
            // it means the water level at 'left' is determined by left_max.
            // The right_max will always be >= height[right], which is > height[left].
            // So, min(left_max, right_max) will be left_max.
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left]; // Update left_max if current bar is taller
                } else {
                    total_water += left_max - height[left]; // Trap water
                }
                left++;
            }
            // When height[right] is smaller than or equal to height[left],
            // it means the water level at 'right' is determined by right_max.
            // The left_max will always be >= height[left], which is >= height[right].
            // So, min(left_max, right_max) will be right_max.
            else {
                if (height[right] >= right_max) {
                    right_max = height[right]; // Update right_max if current bar is taller
                } else {
                    total_water += right_max - height[right]; // Trap water
                }
                right--;
            }
        }

        return total_water;
    }
};