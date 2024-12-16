// https://leetcode.cn/problems/semi-ordered-permutation/
        
class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int min_idx = 0, max_idx = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) min_idx = i;
            else if (nums[i] == n) max_idx = i;
        }
        int res = min_idx + n - 1 - max_idx;
        if (min_idx > max_idx) res -= 1;
        return res;
    }
};
