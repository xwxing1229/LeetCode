// https://leetcode.cn/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0, last = 0, last_last = 0;
        for (int num: nums) {
            res = max(last, last_last + num);
            last_last = last;
            last = res;
        }
        return res;
    }
};
