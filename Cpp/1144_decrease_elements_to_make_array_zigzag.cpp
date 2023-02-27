// https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        return min(zigzag(nums, 0), zigzag(nums, 1));
    }

    int zigzag(vector<int> nums, int start) {
        int res = 0, n = nums.size();
        for (int i = start; i < n; i = i+2) {
            if (i-1 >= 0 && nums[i] >= nums[i-1]) {
                res += (nums[i] - nums[i-1] + 1);
                nums[i] = nums[i-1] - 1;
            }
            if (i+1 < n && nums[i] >= nums[i+1]) {
                res += (nums[i] - nums[i+1] + 1);
                nums[i] = nums[i+1] - 1;
            }
        }
        return res;
    }
};

