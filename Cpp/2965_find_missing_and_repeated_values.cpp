// https://leetcode.cn/problems/find-missing-and-repeated-values/

        
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> check(n*n+1, 0);
        int s = 0;
        for (auto &row: grid) {
            for (auto val: row) {
                check[val] += 1;
                s += val;
            }
        }

        vector<int> res(2, 0);
        int sum2n2 = (1 + n * n) * n * n / 2;
        for (int i = 1; i <= n*n; ++i) {
            if (check[i] == 0) {
                res[1] = i;
                res[0] = s - sum2n2 + res[1];
                break;
            }
            else if (check[i] == 2) {
                res[0] = i;
                res[1] = sum2n2 - s + res[0];
                break;
            }
        }
        return res;
    }
};
