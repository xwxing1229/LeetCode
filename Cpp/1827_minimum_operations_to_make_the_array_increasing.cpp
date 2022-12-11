// https://leetcode.cn/problems/minimum-operations-to-make-the-array-increasing/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, pre = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= pre) {
                pre += 1;
                res += (pre - nums[i]);
            }
            else {
                pre = nums[i];
            }
        }
        return res;
    }
};
