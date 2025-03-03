// # https://leetcode.cn/problems/palindrome-partitioning-iii/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int palindromePartition(string s, int k) {
        // dp[x][j]: minimal number of characters that we need to change to partition
        // s[:j+1] into x+1 palindromes (j >= x).
        // dp[x][j] = min_i dp[x-1][i] + change[i+1][j], i = x-1, ..., j-1.
        
        int n = s.size();
        vector<vector<int>> change(n, vector<int>(n, 0));
        for (int j = 1; j < n; ++j) {
            for (int i = j-1; i >= 0; --i) {
                change[i][j] = change[i+1][j-1] + (s[i] != s[j]);
            }
        }

        vector<vector<int>> dp(k, change[0]);
        for (int x = 1; x < k; ++x) {
            for (int j = x; j < n; ++j) {
                int tmp = n;
                for (int i = x-1; i < j; ++i) {
                    tmp = min(tmp, dp[x-1][i] + change[i+1][j]);
                }
                dp[x][j] = tmp;
            }
        }
        return dp.back().back();
    }
};

int main() {
    Solution sol;
    string s = "aabbc";
    int k = 3;
    cout << sol.palindromePartition(s, k) << '\n';
    return 0;
}