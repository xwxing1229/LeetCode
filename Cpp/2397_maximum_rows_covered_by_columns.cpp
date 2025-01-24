// https://leetcode.cn/problems/maximum-rows-covered-by-columns/

class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        matrix_ = matrix;
        res_ = 0;
        unordered_set<int> cols;
        dfs(0, numSelect, cols);
        return res_;
    }

private:
    void dfs(int idx, int numSelect, unordered_set<int> &cols) {
        int m = matrix_.size(), n = matrix_[0].size();
        if (numSelect == 0) {
            int tmp = 0;
            for (int row = 0; row < m; ++row) {
                tmp += 1;
                for (int col = 0; col < n; ++col) {
                    if (cols.find(col) == cols.end() && matrix_[row][col] == 1) {
                        tmp -= 1;
                        break;
                    }
                }
            }
            res_ = max(res_, tmp);
        }

        for (int col = idx; col < n; ++col) {
            cols.insert(col);
            dfs(col+1, numSelect-1, cols);
            cols.erase(col);
        }
    }

    vector<vector<int>> matrix_;
    int res_;
};
