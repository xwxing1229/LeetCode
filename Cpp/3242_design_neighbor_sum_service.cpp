// https://leetcode.cn/problems/design-neighbor-sum-service/

#include <iostream>
#include <vector>

using namespace std;

class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid) {
        int n = grid.size();
        adjacent_sum_.resize(n*n);
        diagonal_sum_.resize(n*n);
        vector<vector<int>> adj_dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<int>> diag_dirs = {{1,1}, {1,-1}, {-1,1}, {-1,-1}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int adj_sum = 0, diag_sum = 0;
                for (auto &d: adj_dirs) {
                    int i0 = i + d[0], j0 = j + d[1];
                    if (i0 < 0 || i0 >= n || j0 < 0 || j0 >= n) continue;
                    adj_sum += grid[i0][j0];
                }
                for (auto &d: diag_dirs) {
                    int i0 = i + d[0], j0 = j + d[1];
                    if (i0 < 0 || i0 >= n || j0 < 0 || j0 >= n) continue;
                    diag_sum += grid[i0][j0];
                }
                adjacent_sum_[grid[i][j]] = adj_sum;
                diagonal_sum_[grid[i][j]] = diag_sum;
            }
        }
    }
    
    int adjacentSum(int value) {
        return adjacent_sum_[value];
    }
    
    int diagonalSum(int value) {
        return diagonal_sum_[value];
    }

    vector<int> adjacent_sum_, diagonal_sum_;
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

int main() {
    vector<vector<int>> grid = {{0,1,2}, {3,4,5}, {6,7,8}};
    NeighborSum ns(grid);
    cout << ns.adjacentSum(2) << '\n';
    cout << ns.diagonalSum(3) << '\n';
}