// https://leetcode.cn/problems/available-captures-for-rook/

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int res = 0;
        vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] != 'R') continue;
                for (auto d: dirs) {
                    int i0 = i + d.first, j0 = j + d.second;
                    while (i0 >= 0 && i0 < 8 && j0 >= 0 && j0 < 8) {
                        if (board[i0][j0] == 'p') {
                            res += 1;
                            break;
                        }
                        else if (board[i0][j0] == 'B') {
                            break;
                        }
                        i0 += d.first;
                        j0 += d.second;
                    }
                }
            }
        }
        return res;
    }
};
