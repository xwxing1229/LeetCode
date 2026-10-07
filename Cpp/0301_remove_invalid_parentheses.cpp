// https://leetcode.cn/problems/remove-invalid-parentheses/

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> prev;
        prev.insert(s);
        while (true) {
            for (const auto &t: prev) {
                if (isValid(t)) res.push_back(t);
            }
            if (!res.empty()) return res;

            unordered_set<string> curr;
            for (const auto &t: prev) {
                for (int i = 0; i < t.size(); ++i) {
                    if (t[i] == '(' || t[i] == ')') {
                        curr.insert(t.substr(0, i) + t.substr(i+1));
                    }
                }
            }
            prev = move(curr);
        }
    }

    bool isValid(const string &s) {
        int cnt = 0;
        for (char ch: s) {
            if (ch == '(') {
                cnt += 1;
            }
            else if (ch == ')') {
                cnt -= 1;
                if (cnt < 0) {
                    return false;
                }
            }
        }
        return cnt == 0;
    }
};