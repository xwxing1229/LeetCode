// https://leetcode.cn/problems/minimum-operations-to-make-a-uni-value-grid/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int res = 0;
        int rows = grid.size(), cols = grid[0].size();
        int n = rows * cols;
        vector<int> values(n);
        
        int mod = grid[0][0] % x;
        for (int i = 0; i < n; ++i) {
            int val = grid[i/cols][i%cols];
            if (val % x != mod) return -1;
            values[i] = val;
        }
        sort(values.begin(), values.end());
        int mid = values[n/2];
        for (const int &val: values) {
            res += abs(val - mid) / x;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {2,4},
        {6,8}
    };
    int x = 2;
    cout << sol.minOperations(grid, x) << '\n';
    return 0;
}