// https://leetcode.cn/problems/number-of-matching-subsequences/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // Simulate the process.
        vector<double> row(query_row+1, 0);
        row[0] = poured;
        double overflow = 0, overflow_pre = 0;
        for (int i = 0; i < query_row; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (row[j] > 1) overflow = (row[j] - 1) / 2;
                else overflow = 0;

                row[j] = overflow;
                if (j > 0) row[j] += overflow_pre;

                overflow_pre = overflow;
            }
            row[i+1] = overflow;
        }
        double res = 1;
        if (row[query_glass] < res) {
            res = row[query_glass];
        }
        return res;
    }
};
