// https://leetcode.cn/problems/number-of-paths-with-max-score/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        using PII = pair<int, int>;
        int mod = 1e9 + 7;
        vector<PII> direction = {{0,1}, {1,0}, {1,1}};
        int n = board.size();
        vector<vector<PII>> dp(n, vector<PII>(n, {-1, -1}));
        dp.back().back() = {0, 1};
        for (int i = n-2; i >= 0; --i) {
            char ch = board[i].back();
            if (ch == 'X') break;
            dp[i].back().first = dp[i+1].back().first + ch - '0';
            dp[i].back().second = 1;
        }
        for (int j = n-2; j >= 0; --j) {
            char ch = board.back()[j];
            if (ch == 'X') break;
            dp.back()[j].first = dp.back()[j+1].first + ch - '0';
            dp.back()[j].second = 1;
        }
        for (int i0 = n-2; i0 >= 0; --i0) {
            for (int j0 = n-2; j0 >= 0; --j0) {
                char ch = board[i0][j0];
                if (ch == 'X') continue;
                int tmp = -1;
                for (const auto [di, dj]: direction) {
                    int i = i0 + di, j = j0 + dj;
                    tmp = max(tmp, dp[i][j].first);
                }
                if (tmp < 0) continue;

                dp[i0][j0].first = tmp;
                if (ch != 'E') dp[i0][j0].first += ch - '0';
                long ways = 0;
                for (const auto [di, dj]: direction) {
                    int i = i0 + di, j = j0 + dj;
                    if (dp[i][j].first == tmp) {
                        ways = (ways + dp[i][j].second) % mod;
                    }
                }
                dp[i0][j0].second = static_cast<int>(ways);
            }
        }
        vector<int> res = {
            max(0, dp[0][0].first),
            max(0, dp[0][0].second)
        };
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> board = {"E23","2X2","12S"};
    auto res = sol.pathsWithMaxScore(board);
    cout << res[0] << ", " << res[1] << '\n';
    return 0;
}