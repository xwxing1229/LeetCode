// https://leetcode.cn/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum_nums = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum_nums = sum_nums + nums[i];
        }
        return n*(n+1)/2 - sum_nums;
    }
};
