// https://leetcode.cn/problems/spiral-matrix-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        using PII = pair<int, int>;

        vector<vector<int>> res(n, vector<int>(n));

        vector<PII> dirs = {make_pair(0,1), make_pair(1,0), make_pair(0,-1), make_pair(-1,0)};
        int dir_id = 0;
        auto dir = dirs[dir_id];
        int row = 0, top = 0, bottom = n-1;
        int col = 0, left = 0, right = n-1;
        for (int val = 1; val <= n*n; ++val) {
            res[row][col] = val;

            int i = row + dir.first, j = col + dir.second;
            if (i >= top && i <= bottom && j >= left && j <= right) {
                row = i;
                col = j;
                continue;
            }

            dir_id = (dir_id + 1) % 4;
            dir = dirs[dir_id];
            row += dir.first;
            col += dir.second;
            if (i < top) left += 1;
            else if (i > bottom) right -= 1;
            else if (j > right) top += 1;
            else bottom -= 1;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    int n = 4;

    vector<vector<int>> res = solu.generateMatrix(n);
    for (vector<int> row: res) {
        for (int num: row) {
            cout << num << ", ";
        }
        cout << '\n';
    }
    return 0;
}
