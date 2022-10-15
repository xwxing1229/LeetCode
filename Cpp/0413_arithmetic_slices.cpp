// https://leetcode.cn/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        int res = 0, start = 0, diff = nums[1] - nums[0];
        for (int cur = 2; cur < n; ++cur) {
            if (nums[cur] - nums[cur-1] != diff) {
                res = res + numberOfSub(cur - start);

                start = cur - 1;
                diff = nums[cur] - nums[start];
            }
        }
        if (nums[n-1] - nums[n-2] == diff) {
            res = res + numberOfSub(n - start);
        }
        return res;
    }

    int numberOfSub(int n) {
        // Compute 1 + 2 + ... + n-2.
        return (n-1) * (n-2) / 2;
    }
};
