// https://leetcode.cn/problems/best-team-with-no-conflicts/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = make_pair(scores[i], ages[i]);
        }
        sort(pairs.begin(), pairs.end());

        int res = pairs[0].first;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            int score = pairs[i].first, age = pairs[i].second;
            for (int j = 0; j < i; ++j) {
                if (age >= pairs[j].second) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += score;
            res = max(res, dp[i]);
        }
        return res;
    }
};
