// https://leetcode.cn/problems/find-the-number-of-winning-players/

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int res = 0;
        vector<bool> win(n, false);
        vector<unordered_map<int,int>> players(n);
        for (auto &p: pick) {
            int a = p[0], b = p[1];
            if (win[a]) continue;
            players[a][b] += 1;
            if (players[a][b] > a) {
                res += 1;
                win[a] = true;
            }
        }
        return res;
    }
};
