// https://leetcode.cn/problems/minimum-absolute-difference-in-sliding-submatrix/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m-k+1, vector<int>(n-k+1, 0));
        unordered_map<int, int> cnt;

        auto addCol = [&](int tl_row, int col) {
            for (int i = tl_row; i < tl_row+k; ++i) {
                cnt[grid[i][col]] += 1;
            }
        };
        auto removeCol = [&](int tl_row, int col) {
            for (int i = tl_row; i < tl_row+k; ++i) {
                int num = grid[i][col];
                cnt[num] -= 1;
                if (cnt[num] == 0) {
                    cnt.erase(num);
                }
            }
        };
        auto reset = [&](int tl_row, int tl_col) {
            cnt.clear();
            for (int j = tl_col; j < tl_col+k-1; ++j) {
                addCol(tl_row, j);
            }
        };
        auto subMinAbsDiff = [&]() {
            vector<int> nums;
            nums.reserve(cnt.size());
            for (const auto &[k, v]: cnt) {
                nums.push_back(k);
            }
            sort(nums.begin(), nums.end());
            int res = 0;
            for (int i = 0; i < nums.size()-1; ++i) {
                int tmp = nums[i+1] - nums[i];
                if (res == 0 || res > tmp) {
                    res = tmp;
                }
            }
            return res;
        };

        for (int i = 0; i <= m-k; ++i) {
            reset(i, 0);
            for (int j = 0; j <= n-k; ++j) {
                addCol(i, j+k-1);
                res[i][j] = subMinAbsDiff();
                removeCol(i, j);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1,-2,3},
        {2, 3,5}
    };
    int k = 2;
    auto res = sol.minAbsDiff(grid, k);
    for (const auto &row: res) {
        for (const auto &val: row) {
            cout << val << ", ";
        }
        cout << '\n';
    }
    return 0;
}