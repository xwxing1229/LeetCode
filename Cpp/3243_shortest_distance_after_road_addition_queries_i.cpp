// https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-i/

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) dp[i] = i;
        vector<vector<int>> come_from(n);
        vector<int> res(queries.size());
        for (int k = 0; k < queries.size(); ++k) {
            int a = queries[k][0], b = queries[k][1];
            come_from[b].push_back(a);

            dp[b] = min(dp[b], dp[a]+1);
            for (int i = b+1; i < n; ++i) {
                dp[i] = min(dp[i], dp[i-1]+1);
                for (int j: come_from[i]) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
            res[k] = dp.back();
        }
        return res;
    }
};