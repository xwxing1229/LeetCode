// https://leetcode.cn/problems/pond-sizes-lcci/

class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> res;
        int rows = land.size(), cols = land[0].size();
        vector<pair<int, int>> dirs = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1}, {0,1},
            {1,-1}, {1,0}, {1,1}
        };
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (land[i][j] != 0) continue;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                land[i][j] = -1;
                int cnt = 0;
                while (!q.empty()) {
                    auto [curi, curj] = q.front();
                    q.pop();
                    cnt += 1;
                    for (auto d: dirs) {
                        int x = curi + d.first, y = curj + d.second;
                        if (x < 0 || x >= rows || y < 0 || y >= cols) continue;
                        if (land[x][y] != 0) continue;
                        q.push(make_pair(x, y));
                        land[x][y] = -1;
                    }
                }
                res.push_back(cnt);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};