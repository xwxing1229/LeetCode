// https://leetcode.cn/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum_till_now = nums[0], sum_till_last = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum_till_now = max(nums[i], sum_till_last + nums[i]);
            res = max(res, sum_till_now);
            sum_till_last = sum_till_now;
        }
        return res;
    }
};
