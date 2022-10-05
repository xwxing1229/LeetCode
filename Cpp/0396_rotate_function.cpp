// https://leetcode.cn/problems/rotate-function/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) {
            sum = sum + num;
        }
        int res = 0, n = nums.size();
        for (int i = 1; i < n; ++i) {
            res = res + i * nums[i];
        }
        int tmp = res;
        for (int i = n-1; i > 0; --i) {
            tmp = tmp + sum - n * nums[i];
            res = max(res, tmp);
        }
        return res;
    }
};
