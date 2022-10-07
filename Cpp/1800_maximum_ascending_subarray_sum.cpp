// https://leetcode.cn/problems/maximum-ascending-subarray-sum/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0], pre = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                pre = pre + nums[i];
            }
            else {
                pre = nums[i];
            }
            if (pre > res) {
                res = pre;
            }
        }
        return res;
    }
};
