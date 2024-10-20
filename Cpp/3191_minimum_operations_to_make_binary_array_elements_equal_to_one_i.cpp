// https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n-2; ++i) {
            if (nums[i] == 0) {
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
                res += 1;
            }
        }
        return (nums[n-1] == 1 && nums[n-2] == 1) ? res : -1;
    }
};
