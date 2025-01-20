// https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end());
        vector<int> dp(n+2, n);
        dp[0] = 0;
        dp[1] = 0;
        if (n > 1 && tasks[1] == tasks[0]) {
            dp[3] = 1;
        }
        if (n > 2 && tasks[2] == tasks[1] && tasks[1] == tasks[0]) {
            dp[4] = 1;
        }
        for (int i = 2; i < n; ++i) {
            if (tasks[i] != tasks[i-1]) continue;
            dp[i+2] = min(dp[i+2], dp[i]+1);
            if (tasks[i] == tasks[i-2]) {
                dp[i+2] = min(dp[i+2], dp[i-1]+1);
            }
        }
        return dp.back() == n ? -1 : dp.back();
    }
};
