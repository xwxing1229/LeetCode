// https://leetcode.cn/problems/process-string-with-special-operations-i/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string processStr(string s) {
        string res = "";
        for (const auto ch: s) {
            if (ch == '*') {
                if (res.size() > 0) {
                    res.pop_back();
                }
            }
            else if (ch == '#') {
                res += res;
            }
            else if (ch == '%') {
                res = string(res.rbegin(), res.rend());
            }
            else {
                res += ch;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "a#b%*";
    cout << sol.processStr(s) << '\n';
    return 0;
}