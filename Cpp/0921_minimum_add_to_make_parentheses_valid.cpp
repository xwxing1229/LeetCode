// https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/

#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0, cnt = 0;
        for (char ch: s) {
            if (ch == '(') {
                cnt += 1;
            }
            else {
                cnt -= 1;
                if (cnt < 0) {
                    res -= cnt;
                    cnt = 0;
                }
            }
        }
        return res + cnt;
    }
};