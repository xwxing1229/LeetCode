// https://leetcode.cn/problems/sum-of-values-at-indices-with-k-set-bits/
        
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = i, ones = 0;
            while (idx > 0) {
                if ((idx & 1) == 1) {
                    ones += 1;
                }
                idx = (idx >> 1);
            }
            if (ones == k) {
                res += nums[i];
            }
        }
        return res;
    }
};
