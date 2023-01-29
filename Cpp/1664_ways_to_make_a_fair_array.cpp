// https://leetcode.cn/problems/ways-to-make-a-fair-array/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        else if (n == 2) return 0;

        vector<int> cumsum(n, nums[0]);
        cumsum[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            cumsum[i] = cumsum[i-2] + nums[i];
        }

        int oddsum = cumsum[n-1], evensum = cumsum[n-2];
        if (n % 2 == 1) {
            oddsum = cumsum[n-2];
            evensum = cumsum[n-1];
        }
        int res = 0;
        if (evensum - nums[0] == oddsum) res += 1;
        if (oddsum - nums[1] + nums[0] == evensum - nums[0]) res += 1;
        for (int i = 2; i < n; ++i) {
            int oddsum_new = 0, evensum_new = 0;
            if (i % 2 == 0) {
                oddsum_new = cumsum[i-1] + evensum - cumsum[i];
                evensum_new = cumsum[i-2] + oddsum - cumsum[i-1];
            }
            else {
                oddsum_new = cumsum[i-2] + evensum - cumsum[i-1];
                evensum_new = cumsum[i-1] + oddsum - cumsum[i];
            }
            if (oddsum_new == evensum_new) res += 1;
        }
        return res;
    }
};
