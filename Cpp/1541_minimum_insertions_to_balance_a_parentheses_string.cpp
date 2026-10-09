// https://leetcode.cn/problems/minimum-insertions-to-balance-a-parentheses-string/

#include <string>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int cnt = 0, i = 0, n = s.size();
        while (i < n) {
            if (s[i] == '(') {
                cnt += 2;
                i += 1;
                continue;
            }

            cnt -= 2;
            if (i + 1 < n && s[i+1] == ')') {
                i += 2;
            }
            else {
                i += 1;
                res += 1; // insert a ')'
            }
            if (cnt < 0) {
                res += 1; // insert a '('
                cnt = 0;
            }
        }
        res += cnt;
        return res;
    }
};