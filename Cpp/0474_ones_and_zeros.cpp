// https://leetcode.cn/problems/ones-and-zeroes/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<int> cnt0(len, 0);
        for (int i = 0; i < len; ++i) {
            for (char ch: strs[i]) cnt0[i] += (ch == '0');
        }
        vector<vector<vector<int>>> record(len, vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        // dfs(i, j, k): maximum size of subset of strs[0: k+1] that satisfies
        //               number of 0 <= i and number of 1 <= j
        //               0 <= k < len(strs)
        auto dfs = [&](auto &&self, int i, int j, int k) {
            if (k < 0) return 0;
            if (record[k][i][j] >= 0) return record[k][i][j];
            int res = self(self, i, j, k-1);
            int cnt1 = strs[k].size() - cnt0[k]; // subset does not contain strs[k]
            if (cnt0[k] <= i && cnt1 <= j) {
                res = max(res, self(self, i-cnt0[k], j-cnt1, k-1)+1); // subset contains strs[k]
            }
            record[k][i][j] = res;
            return res;
        };

        return dfs(dfs, m, n, len-1);
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"10","0001","111001","1","0"};
    int m = 5, n = 3;
    cout << sol.findMaxForm(strs, m, n) << '\n';
    return 0;
}