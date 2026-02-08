// https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int tmp = 0;
        for (const char ch: s) {
            tmp += (ch == 'a');
        }
        int res = tmp;
        for (const char ch: s) {
            if (ch == 'a') {
                tmp -= 1;
            }
            else {
                tmp += 1;
            }
            res = min(res, tmp);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "aababbab";
    cout << sol.minimumDeletions(s) << '\n';
    return 0;
}