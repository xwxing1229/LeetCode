// https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        // max_first[i]: max(nums[j-firstLen+1] + ... + nums[j]) for j = firstLen-1, ..., i
        // max_second[i]: max(nums[j-secondLen+1] + ... + nums[j]) for j = secondLen-1, ..., i
        vector<int> max_first(n), max_second(n), cum_sum(n+1);
        int s_first = 0, s_second = 0;
        for (int i = 0; i < n; ++i) {
            s_first += nums[i];
            s_second += nums[i];
            if (i >= firstLen - 1) {
                max_first[i] = s_first;
                s_first -= nums[i - firstLen + 1];
                if (i > firstLen - 1 && max_first[i] < max_first[i-1]) {
                    max_first[i] = max_first[i-1];
                }
            }
            if (i >= secondLen - 1) {
                max_second[i] = s_second;
                s_second -= nums[i - secondLen + 1];
                if (i > secondLen - 1 && max_second[i] < max_second[i-1]) {
                    max_second[i] = max_second[i-1];
                }
            }
            cum_sum[i+1] = cum_sum[i] + nums[i];
        }

        int res = 0;
        vector<int> dp_first(n), dp_second(n);
        for (int i = firstLen + secondLen - 1; i < n; ++i) {
            dp_first[i] = cum_sum[i+1] - cum_sum[i+1-firstLen] + max_second[i-firstLen];
            dp_second[i] = cum_sum[i+1] - cum_sum[i+1-secondLen] + max_first[i-secondLen];
            res = max(res, max(dp_first[i], dp_second[i]));
        }
        return res;
    }
};