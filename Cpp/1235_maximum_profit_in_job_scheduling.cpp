// https://leetcode.cn/problems/maximum-profit-in-job-scheduling/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> idxs(n);
        for (int i = 0; i < n; ++i) {
            idxs[i] = i;
        }
        sort(idxs.begin(), idxs.end(), [&](const int i, const int j) {
            return endTime[i] < endTime[j];
        });
        
        // dp[i]: maximum profit until the ith job (the ith job is not necessarily
        //        selected).
        vector<int> dp(n, profit[idxs[0]]);
        for (int i = 1; i < n; ++i) {
            int left = 0, right = i-1;
            int start = startTime[idxs[i]];
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (endTime[idxs[mid]] <= start) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }

            int tmp = profit[idxs[i]];
            if (left > 0) {
                tmp += dp[left-1];
            }

            if (tmp > dp[i-1]) {
                dp[i] = tmp;
            }
            else {
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};
