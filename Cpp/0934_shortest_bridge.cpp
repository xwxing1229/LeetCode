// https://leetcode.cn/problems/shortest-bridge/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        // Find one island and its boundary.
        queue<pair<int,int>> boundary;
        findIsland(grid, boundary);

        // Expand the boundary to find a shorest bridge.
        int rows = grid.size(), cols = grid[0].size();
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int res = 0;
        while (!boundary.empty()) {
            res += 1;
            int k = boundary.size();
            while (k > 0) {
                pair<int,int> pos = boundary.front();
                boundary.pop();
                k -= 1;
                for (pair<int,int> dir: dirs) {
                    int i = pos.first + dir.first, j = pos.second + dir.second;
                    if ((i < 0) || (i >= rows) || (j < 0) || (j >= cols)) {
                        continue;
                    }

                    if (grid[i][j] == 0) {
                        grid[i][j] = 2;
                        boundary.push(make_pair(i,j));
                    }
                    else if (grid[i][j] == 1) {
                        return res;
                    }
                }
            }
        }
        return 0;
    }

private:
    void findIsland(vector<vector<int>>& grid, queue<pair<int,int>>& boundary) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, boundary);
                    return;
                }
            }
        }
    }

    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int,int>>& boundary) {
        if ((i < 0) || (i >= grid.size()) || (j < 0) || (j >= grid[0].size())) {
            return;
        }
        if (grid[i][j] == 0) {
            boundary.push(make_pair(i,j));
            grid[i][j] = 2;
        }
        else if (grid[i][j] == 1) {
            grid[i][j] = 2;
            dfs(grid, i-1, j, boundary);
            dfs(grid, i+1, j, boundary);
            dfs(grid, i, j-1, boundary);
            dfs(grid, i, j+1, boundary);
        }
    }
};
