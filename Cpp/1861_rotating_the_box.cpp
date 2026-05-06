// https://leetcode.cn/problems/rotating-the-box/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> res(m, vector<char>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = boxGrid[n-1-j][i];
            }
        }
        for (int j = 0; j < n; ++j) {
            int empty = m - 1;
            for (int i = m-1; i >= 0; --i) {
                char ch = res[i][j];
                if (ch == '#') {
                    res[i][j] = '.';
                    res[empty][j] = '#';
                    empty -= 1;
                }
                else if (ch == '*') {
                    empty = i - 1;
                }
                else {
                    empty = max(empty, i);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> box = {
        {'#', '.', '*', '.'},
        {'#', '#', '*', '.'}
    };
    // out:
    // {'#','.'},
    // {'#','#'},
    // {'*','*'},
    // {'.','.'}
    auto res = sol.rotateTheBox(box);
    for (const auto &row: res) {
        for (const auto &val: row) cout << val << ", ";
        cout << '\n';
    }
    return 0;
}