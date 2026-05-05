// https://leetcode.cn/problems/longest-balanced-substring-i/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> cnt;
            for (int j = i; j < n; ++j) {
                cnt[s[j]] += 1;
                int value = cnt[s[j]];
                bool balanced = true;
                for (const auto &[k, v]: cnt) {
                    if (value != v) {
                        balanced = false;
                        break;
                    }
                }
                if (balanced) {
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "abbac";
    cout << sol.longestBalanced(s) << '\n';
    return 0;
}