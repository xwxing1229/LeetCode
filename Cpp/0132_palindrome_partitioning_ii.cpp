// https://leetcode.cn/problems/palindrome-partitioning-ii/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        // dp[j]: minimum cuts needed for a palindrome partitioning of s[:j+1].
        // dp[j] = min_i dp[i] + 1, for i = 0, ..., j-1 and s[i+1:j+1] is a palindrome.

        int n = s.size();
        vector<vector<bool>> palindrome(n, vector<bool>(n, true));
        for (int j = 1; j < n; ++j) {
            for (int i = j-1; i >= 0; --i) {
                palindrome[i][j] = (s[i] == s[j] && palindrome[i+1][j-1]);
            }
        }

        vector<int> dp(n, 0);
        for (int j = 1; j < n; ++j) {
            if (palindrome[0][j]) continue;
            int tmp = n - 1;
            for (int i = 0; i < j; ++i) {
                if (palindrome[i+1][j]) {
                    tmp = min(tmp, dp[i] + 1);
                }
            }
            dp[j] = tmp;
        }
        return dp.back();
    }
};

int main() {
    Solution sol;
    string s = "aab";
    cout << sol.minCut(s) << '\n';    
    return 0;
}