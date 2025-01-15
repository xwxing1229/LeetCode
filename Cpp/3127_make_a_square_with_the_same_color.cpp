// https://leetcode.cn/problems/make-a-square-with-the-same-color/

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int cnt = 0;
                if (grid[i][j] == 'W') cnt += 1;
                if (grid[i][j+1] == 'W') cnt += 1;
                if (grid[i+1][j] == 'W') cnt += 1;
                if (grid[i+1][j+1] == 'W') cnt += 1;
                if (cnt != 2) return true;
            }
        }
        return false;
    }
};
