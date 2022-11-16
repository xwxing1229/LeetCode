// https://leetcode.cn/problems/global-and-local-inversions/

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if ((nums[i] - i < -1) || (nums[i] - i > 1)) {
                return false;
            }
        }
        return true;

        // Another method:
        // nums[i] < min(nums[i+2], nums[i+3], ..., nums[n-1]), so just
        // scan nums in the reverse direction and maintain a minimum value.
    }
};
