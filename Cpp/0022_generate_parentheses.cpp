// https://leetcode.cn/problems/generate-parentheses/

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<unordered_set<string>> st(n+1);
        st[1].insert("()");
        for (int k = 2; k <= n; ++k) {
            for (int i = 1; i <= k/2; ++i) {
                int j = k - i;
                for (const auto &s1: st[i]) {
                    for (const auto &s2: st[j]) {
                        st[k].insert(s1 + s2);
                        st[k].insert(s2 + s1);
                    }
                }
            }
            for (const auto &s1: st[k-1]) {
                st[k].insert("(" + s1 + ")");
            }
        }
        return vector<string>(st[n].begin(), st[n].end());
    }
};