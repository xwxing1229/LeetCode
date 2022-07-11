// https://leetcode.cn/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        // Similar to #198.
        // res_1: check nums[0], ..., nums[n-2];
        // res_2: check nums[1], ..., nums[n-1].
        int res_1 = nums[0], last_1 = res_1, last_last_1 = 0;
        int res_2 = 0, last_2 = res_2, last_last_2 = 0;
        int n = nums.size();
        for (int i = 1; i < n-1; ++i) {
            res_1 = max(res_1, last_last_1 + nums[i]);
            last_last_1 = last_1;
            last_1 = res_1;

            res_2 = max(res_2, last_last_2 + nums[i]);
            last_last_2 = last_2;
            last_2 = res_2;
        }
        res_2 = max(res_2, last_last_2 + nums[n-1]);

        return max(res_1, res_2);
    }
};
