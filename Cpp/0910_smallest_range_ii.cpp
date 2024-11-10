// https://leetcode.cn/problems/smallest-range-ii/

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = nums.back() - nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            // Increase: nums[k] for k = 0, 1, ..., i-1.
            // Decrease: nums[k] for k = i, i+1, ..., n-1.
            int cur_max = max(nums[i-1] + k, nums.back() - k);
            int cur_min = min(nums[0] + k, nums[i] - k);
            res = min(res, cur_max - cur_min);
        }
        return res;
    }
};
