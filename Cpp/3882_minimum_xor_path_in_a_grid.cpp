// https://leetcode.cn/problems/minimum-xor-path-in-a-grid/

#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int res = __INT_MAX__;
        
        // (a ^ b) <= (a | b).
        int or_all = 0;
        for (const auto &row: grid) {
            for (auto val: row) {
                or_all |= val;
            }
        }
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> seen(
            m,
            vector<vector<bool>>(n, vector<bool>(or_all+1, false))
        );

        auto dfs = [&](auto &&self, int i, int j, int curr) {
            if (res == 0) {
                return;
            }
            if (i < 0 || j < 0 || seen[i][j][curr]) {
                return;
            }
            seen[i][j][curr] = true;
            curr ^= grid[i][j];
            if (i == 0 && j == 0) {
                res = min(res, curr);
            }
            self(self, i-1, j, curr);
            self(self, i, j-1, curr);
        };

        dfs(dfs, m-1, n-1, 0);

        return res;
    }
};