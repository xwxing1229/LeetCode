// https://leetcode.cn/problems/total-hamming-distance/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 30; ++i) {
            int ones = 0;
            for (int num: nums) {
                ones += ((num >> i) & 1);
            }
            res += ones * (n - ones);
        }
        return res;
    }
};
