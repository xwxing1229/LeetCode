// https://leetcode.cn/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1) {
            return triangle[0][0];
        }
        else if (n == 2) {
            return triangle[0][0] + min(triangle[1][0], triangle[1][1]);
        }

        vector<int> res(n);
        res[0] = triangle[0][0] + triangle[1][0];
        res[1] = triangle[0][0] + triangle[1][1];
        for (int row = 2; row < n; ++row) {
            int last = res[0];

            res[0] = res[0] + triangle[row][0];
            res[row] = res[row-1] + triangle[row][row];

            for (int i = 1; i < row; ++i) {
                int tmp = triangle[row][i] + min(last, res[i]);
                last = res[i];
                res[i] = tmp;
            }
        }
        return *min_element(res.begin(), res.end());
    }
};
