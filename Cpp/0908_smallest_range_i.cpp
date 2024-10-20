// https://leetcode.cn/problems/smallest-range-i/

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int num_max = nums[0], num_min = nums[0];
        for (int num: nums) {
            num_max = max(num_max, num);
            num_min = min(num_min, num);
        }
        return max(0, num_max - num_min - 2*k);
    }
};
