// https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int i = 0;
        while (i < nums.size() && nums[i] < 0) {
            i += 1;
        }
        int res = i;
        while (i < nums.size() && nums[i] == 0) {
            i += 1;
        }
        res = max(res, (int)nums.size()-i);
        return res;
    }
};
