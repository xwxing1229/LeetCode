// https://leetcode.cn/problems/partition-array-for-maximum-sum/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // For i = 0, 1 ,..., k-1,
        //   dp[i] = x * (i+1),
        // where x = max(arr[0], ..., arr[i]).
        // For i = k, k+1, ..., n-1,
        //   dp[i] = max(dp[j] + x * (i-j)),
        // where x = max(arr[j+1], ..., arr[i]) for j = i-k+1, ..., i-1.
        int n = arr.size();
        vector<int> dp(n);
        int max_cur = arr[0];
        for (int i = 0; i < k; ++i) {
            if (max_cur < arr[i]) {
                max_cur = arr[i];
            }
            dp[i] = max_cur * (i+1);
        }

        for (int i = k; i < n; ++i) {
            max_cur = arr[i];
            dp[i] = dp[i-1] + max_cur;
            for (int j = 0; j < k; ++j) {
                if (max_cur < arr[i-j]) {
                    max_cur = arr[i-j];
                }
                int tmp = dp[i-j-1] + max_cur * (j+1);
                if (tmp > dp[i]) {
                    dp[i] = tmp;
                }
            }
        }
        return dp[n-1];
    }
};