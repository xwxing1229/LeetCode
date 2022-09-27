// https://leetcode.cn/problems/wiggle-subsequence/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1, diff_pre = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int diff = nums[i] - nums[i-1];
            if (diff > 0) {
                diff = 1;
                if (diff != diff_pre) {
                    res = res + 1;
                }
                diff_pre = 1;
            }
            else if (diff < 0) {
                diff = -1;
                if (diff != diff_pre) {
                    res = res + 1;
                }
                diff_pre = -1;
            }
        }
        return res;
    }
};
