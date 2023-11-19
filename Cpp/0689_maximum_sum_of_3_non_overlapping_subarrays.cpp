// https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> res(3);
        int sum1 = 0, max_sum1 = 0, max_sum1_idx = 0;
        int sum2 = 0, max_sum12 = 0, max_sum12_idx1 = 0, max_sum12_idx2 = 0;
        int sum3 = 0, max_sum123 = 0;
        for (int i = k+k; i < nums.size(); ++i) {
            sum1 += nums[i-k-k];
            sum2 += nums[i-k];
            sum3 += nums[i];
            if (i >= k+k+k-1) {
                if (sum1 > max_sum1) {
                    max_sum1 = sum1;
                    max_sum1_idx = i-k-k-k+1;
                }
                if (max_sum1 + sum2 > max_sum12) {
                    max_sum12 = max_sum1 + sum2;
                    max_sum12_idx1 = max_sum1_idx;
                    max_sum12_idx2 = i-k-k+1;
                }
                if (max_sum12 + sum3 > max_sum123) {
                    max_sum123 = max_sum12 + sum3;
                    res[0] = max_sum12_idx1;
                    res[1] = max_sum12_idx2;
                    res[2] = i-k+1;
                }
                sum1 -= nums[i-k-k-k+1];
                sum2 -= nums[i-k-k+1];
                sum3 -= nums[i-k+1];
            }
        }
        return res;
    }
};
