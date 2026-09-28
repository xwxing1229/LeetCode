// https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/

#include <string>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int cnt = 0;
        for (char ch: s) {
            cnt += (ch == '(') - (ch == ')');
            res = max(res, cnt);
        }
        return res;
    }
};