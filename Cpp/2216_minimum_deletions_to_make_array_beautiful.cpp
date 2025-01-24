// https://leetcode.cn/problems/minimum-deletions-to-make-array-beautiful/

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int res = 0;
        int i = 0, n = nums.size();
        while (i < n) {
            int cur = nums[i];
            i += 1;
            while (i < n && nums[i] == cur) {
                i += 1;
                res += 1;
            }
            if (i == n) {
                res += 1;
            }
            i += 1;
        }
        return res;
    }
};