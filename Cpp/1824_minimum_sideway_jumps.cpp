// https://leetcode.cn/problems/minimum-sideway-jumps/

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> dp_pre(3, 1);
        dp_pre[1] = 0;
        for (int i = 1; i < n; ++i) {
            vector<int> dp(3, n);
            int obs = obstacles[i];
            for (int lane = 0; lane < 3; ++lane) {
                if (lane == obs - 1) continue;
                for (int other = 0; other < 3; ++other) {
                    if ((other == lane) && (dp_pre[other] < n)) {
                        dp[lane] = dp_pre[lane];
                    }
                    else if ((other == obs - 1) && (lane == obstacles[i-1] - 1)) {
                        dp[lane] = min(dp[lane], dp_pre[other] + 2);
                    }
                    else {
                        dp[lane] = min(dp[lane], dp_pre[other] + 1);
                    }
                }
            }
            for (int lane = 0; lane < 3; ++lane) {
                dp_pre[lane] = dp[lane];
            }
        }
        return *min_element(dp_pre.begin(), dp_pre.end());
    }
};