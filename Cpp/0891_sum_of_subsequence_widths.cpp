// https://leetcode.cn/problems/sum-of-subsequence-widths/

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        long end_at_i = 0, pow2 = 2;
        int mod = 1000000007;
        for (int i = 1; i < nums.size(); ++i) {
            end_at_i = ((nums[i]-nums[i-1]) * (pow2-1) + 2*end_at_i) % mod;
            pow2 = pow2 * 2 % mod;
            res = (end_at_i + res) % mod;
        }
        return res;
    }
};