// https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size(), i = 0;
        while (i < n && s[i] == '1') i += 1;
        int j = i;
        while (j < n && s[j] == '0') j += 1;
        return j == n;
    }
};

int main() {
    Solution sol;
    string s = "1001";
    cout << sol.checkOnesSegment(s) << '\n';
    return 0;
}
