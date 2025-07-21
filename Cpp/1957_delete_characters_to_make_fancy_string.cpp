// https://leetcode.cn/problems/delete-characters-to-make-fancy-string/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string res = "-";
        int cnt = 0;
        for (const auto ch: s) {
            if (ch != res.back()) {
                res += ch;
                cnt = 1;
            }
            else if (cnt < 2) {
                res += ch;
                cnt += 1;
            }
        }
        return res.substr(1);
    }
};

int main() {
    Solution sol;
    string s = "leeetcode";
    cout << sol.makeFancyString(s) << '\n';
    return 0;
}