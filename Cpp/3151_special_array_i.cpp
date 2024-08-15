// https://leetcode.cn/problems/special-array-i/

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int pre = nums[0] % 2;
        for (int i = 1; i < nums.size(); ++i) {
            int cur = nums[i] % 2;
            if (pre + cur != 1) {
                return false;
            }
            pre = cur;
        }
        return true;
    }
};
