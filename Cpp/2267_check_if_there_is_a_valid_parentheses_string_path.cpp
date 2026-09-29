// https://leetcode.cn/problems/check-if-there-is-a-valid-parentheses-string-path/

#include <vector>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m+n)%2 == 0 || grid[0][0] == ')' || grid.back().back() == '(') {
            return false;
        }
        vector<vector<vector<bool>>> visit(m, vector<vector<bool>>(n, vector<bool>((m+n+1)/2, false)));
        auto dfs = [&](auto &&self, int i, int j, int c) -> bool {
            // Cannot make c = 0 even though there are all ')' on the remaining path.
            if (c > m - i + n - j - 1) return false;
            // End point.
            if (i == m-1 && j == n-1) return c == 1;
            // Already checked.
            if (visit[i][j][c]) return false;
            visit[i][j][c] = true;

            c += (grid[i][j] == '(') ? 1 : -1;
            if (c < 0) return false;
            return (i < m-1 && self(self, i+1, j, c))
                || (j < n-1 && self(self, i, j+1, c));
        };
        return dfs(dfs, 0, 0, 0);
    }
};