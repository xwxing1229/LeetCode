// https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Let n = nums.size() and sort nums.
        // If n % 2 == 0, the final element should be any integer in the range
        // [nums[n//2-1], nums[n//2]].
        // If n % 2 == 1, the final element should be nums[n//2].
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int idx = (n+1) / 2;
        int sum_sub_1 = 0, sum_sub_2 = 0;
        for (int i = 0; i < idx; ++i) {
            sum_sub_1 += nums[i];
        }
        for (int i = idx; i < n; ++i) {
            sum_sub_2 += nums[i];
        }

        int res = sum_sub_2 - sum_sub_1;
        if (n % 2 == 1) {
            res += nums[idx-1];
        }
        return res;
    }
};
