// https://leetcode.cn/problems/palindrome-partitioning-iv/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        auto update = [&](int left, int right) {
            while (left >= 0 and right < n and s[left] == s[right]) {
                palindrome[left][right] = true;
                left -= 1;
                right += 1;
            }
        };

        for (int i = 0; i < n; ++i) {
            update(i, i);
            update(i, i+1);
        }

        for (int i = 1; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (palindrome[0][i-1] && palindrome[i][j-1] && palindrome[j][n-1]) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s = "abcbdd";
    cout << sol.checkPartitioning(s) << '\n';
    return 0;
}