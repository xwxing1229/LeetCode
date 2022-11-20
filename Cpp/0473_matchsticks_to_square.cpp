// https://leetcode.cn/problems/matchsticks-to-square/

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int s = 0;
        for (int match: matchsticks) {
            s += match;
        }
        if (s % 4 != 0) return false;
        int avg = s / 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> edges(4, 0);
        return dfs(matchsticks, avg, 0, edges);
    }

private:
    bool dfs(vector<int>& matchsticks, int avg, int cur, vector<int>& edges) {
        if (cur == matchsticks.size()) return true;
        for (int i = 0; i < 4; ++i) {
            edges[i] += matchsticks[cur];
            if ((edges[i] <= avg) && (dfs(matchsticks, avg, cur+1, edges))) {
                return true;
            }
            edges[i] -= matchsticks[cur];
        }
        return false;
    }
};
