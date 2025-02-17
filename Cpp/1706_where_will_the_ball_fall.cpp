// https://leetcode.cn/problems/where-will-the-ball-fall/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n, -1);

        auto fall = [&](int start) {
            int j = start;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] > 0 && j+1 < n && grid[i][j+1] > 0) j += 1;
                else if (grid[i][j] < 0 && j-1 >= 0 && grid[i][j-1] < 0) j -= 1;
                else return -1;
            }
            return j;
        };
        
        for (int j = 0; j < n; ++j) {
            res[j] = fall(j);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1,1,1,-1,-1},
        {1,1,1,-1,-1},
        {-1,-1,-1,1,1},
        {1,1,1,1,-1},
        {-1,-1,-1,-1,-1}
    };
    auto res = sol.findBall(grid);
    for (auto val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}