// https://leetcode.cn/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s = 0;
        for (int num: nums) {
            s += num;
        }
        int s_left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (s_left == s - s_left - nums[i]) {
                return i;
            }
            s_left += nums[i];
        }
        return -1;
    }
};
