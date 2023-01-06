// https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int res = -1, n = nums.size();
        vector<int> lsum(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            lsum[i] = lsum[i-1] + nums[i-1];
        }
        if (lsum[n] < x) return res;

        int rsum = 0, left = n;
        for (int right = n-1; right >= -1; --right) {
            while ((left > 0) && (lsum[left] + rsum > x)) {
                left -= 1;
            }
            if (lsum[left] + rsum == x) {
                int tmp = left + n - 1 - right;
                if ((res < 0) || (res > tmp)) {
                    res = tmp;
                }
            }
            if (right >= 0) rsum += nums[right];
        }
        return res;
    }
};
