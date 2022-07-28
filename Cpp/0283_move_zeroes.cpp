// https://leetcode.cn/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int idx_0 = 0, idx = 0;
        while (idx < n) {
            while ((idx_0 < n) && (nums[idx_0] != 0)) {
                idx_0 = idx_0 + 1;
            }

            idx = idx_0 + 1;
            while ((idx < n) && (nums[idx] == 0)) {
                idx = idx + 1;
            }

            if ((idx_0 == n) || (idx == n)) {
                break;
            }

            nums[idx_0] = nums[idx];
            nums[idx] = 0;
        }
    }
};
