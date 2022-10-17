// https://leetcode.cn/problems/pacific-atlantic-water-flow/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        // Search for positions from which rain can flow to the Pacific Ocean.
        vector<vector<int>> check(rows, vector<int>(cols,0));
        vector<int> start = {0,0};
        for (int i = 0; i < rows; ++i) {
            start[0] = i;
            dfs(heights, start, pa, check);
        }
        start[0] = 0;
        for (int j = 0; j < cols; ++j) {
            start[1] = j;
            dfs(heights, start, pa, check);
        }
        // Search for positions from which rain can flow to the Atlantic Ocean.
        for (vector<int>& vec: check) {
            fill(vec.begin(), vec.end(), 0);
        }
        start[1] = cols - 1;
        for (int i = 0; i < rows; ++i) {
            start[0] = i;
            dfs(heights, start, at, check);
        }
        start[0] = rows - 1;
        for (int j = 0; j < cols; ++j) {
            start[1] = j;
            dfs(heights, start, at, check);
        }

        vector<vector<int>> res;
        for (auto iter = pa.begin(); iter != pa.end(); ++iter) {
            if (at.find(*iter) != at.end()) {
                start[0] = *iter / 500;
                start[1] = *iter % 500;
                res.push_back(start);
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<int>& start,
        unordered_set<int>& ocean, vector<vector<int>>& check) {
        if (check[start[0]][start[1]]) return;

        ocean.insert(500*start[0]+start[1]);
        check[start[0]][start[1]] = 1;

        for (vector<int> d: dirs) {
            vector<int> pos = {start[0]+d[0], start[1]+d[1]};
            if ((pos[0] >= 0) && (pos[0] < heights.size()) &&
                (pos[1] >= 0) && (pos[1] < heights[0].size())) {
                if (heights[pos[0]][pos[1]] >= heights[start[0]][start[1]]) {
                    dfs(heights, pos, ocean, check);
                }
            }
        }
    }

    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    unordered_set<int> pa, at;
};
