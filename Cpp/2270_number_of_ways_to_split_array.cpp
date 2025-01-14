// https://leetcode.cn/problems/number-of-ways-to-split-array/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<long long> cumsum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            cumsum[i+1] = cumsum[i] + nums[i];
        }
        long long s = cumsum.back();
        for (int i = 0; i < n-1; ++i) {
            if (cumsum[i+1] >= s - cumsum[i+1]) {
                res += 1;
            }
        }
        return res;
    }
};
