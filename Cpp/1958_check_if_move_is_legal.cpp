// https://leetcode.cn/problems/check-if-move-is-legal/

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int m = board.size(), n = board[0].size();
        vector<pair<int,int>> dirs = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
        for (auto &d: dirs) {
            int i = rMove + d.first, j = cMove + d.second;
            bool valid = false;
            int length = 1;
            while ((i >= 0) && (i < m) && (j >= 0) && (j < n)) {
                length += 1;
                if (board[i][j] == color) {
                    valid = true;
                    break;
                }
                else if (board[i][j] == '.') {
                    break;
                }
                i += d.first;
                j += d.second;
            }
            if (valid && length >= 3) {
                return true;
            }
        }
        return false;
    }
};
