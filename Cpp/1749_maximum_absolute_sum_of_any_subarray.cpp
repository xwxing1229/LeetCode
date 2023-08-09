// https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int dp_max = nums[0], dp_min = nums[0];
        int res = abs(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            dp_max = max(dp_max + nums[i], nums[i]);
            dp_min = min(dp_min + nums[i], nums[i]);
            res = max(res, max(abs(dp_max), abs(dp_min)));
        }
        return res;
    }
};