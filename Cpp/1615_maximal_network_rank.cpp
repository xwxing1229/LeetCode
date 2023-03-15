// https://leetcode.cn/problems/maximal-network-rank/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> cnt;
        vector<vector<int>> connect(n, vector<int>(n, 0));
        for (auto &road: roads) {
            int x = road[0], y = road[1];
            cnt[x] += 1;
            cnt[y] += 1;
            connect[x][y] = 1;
            connect[y][x] = 1;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int tmp = cnt[i] + cnt[j] - connect[i][j];
                if (tmp > res) {
                    res = tmp;
                }
            }
        }
        return res;
    }
};
