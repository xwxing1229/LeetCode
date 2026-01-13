// https://leetcode.cn/problems/separate-squares-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double ymin = squares[0][1], ymax = squares[0][1]+squares[0][2];
        for (const auto &square: squares) {
            ymin = min(ymin, (double)square[1]);
            ymax = max(ymax, (double)square[1]+square[2]);
        }
        double res = ymax;
        double eps = 1e-5;
        while (ymax - ymin > eps) {
            double mid = ymin + (ymax - ymin) / 2;
            double diff = 0; // above - below
            for (const auto &square: squares) {
                double y = square[1], l = square[2];
                if (mid <= y) diff += l * l;
                else if (mid >= y + l) diff -= l * l;
                else diff += (2 * y + l - 2 * mid) * l;
            }
            if (diff <= 0) ymax = mid;
            else ymin = mid;
            res = mid;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> squares = {{0,0,2}, {1,1,1}};
    cout << sol.separateSquares(squares) << '\n';
    return 0;
}