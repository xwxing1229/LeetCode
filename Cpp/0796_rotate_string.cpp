// https://leetcode.cn/problems/rotate-string/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        s += s;
        for (int i = 0; i < n; ++i) {
            if (s.substr(i, n) == goal) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s = "abcde";
    string goal = "cdeab";
    cout << sol.rotateString(s, goal) << '\n';
    return 0;
}