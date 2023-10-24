// https://leetcode.cn/problems/queens-that-can-attack-the-king/

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<pair<int,int>> dirs = {
            {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}
        };
        vector<int> valid(8,1), s(64,0);
        for (auto &queen: queens) {
            s[queen[0]*8+queen[1]] = 1;
        }
        int step = 1;
        vector<vector<int>> res;
        while (step < 8) {
            for (int i = 0; i < 8; ++i) {
                if (!valid[i]) continue;

                int x = king[0] + step * dirs[i].first;
                int y = king[1] + step * dirs[i].second;
                int cur = x * 8 + y;
                if (x < 0 || x >= 8 || y < 0 || y >= 8) {
                    valid[i] = 0;
                }
                else if (s[cur] == 1) {
                    res.push_back((vector<int>){x,y});
                    valid[i] = 0;
                }
            }
            step += 1;
        }
        return res;
    }
};
