// https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-i/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();
        for (int i = 0; i < n-2; i++) {
            if (s1[i] == s2[i]) {
                continue;
            }
            else if (s1[i+2] == s2[i]) {
                swap(s1[i], s1[i+2]);
            }
            else {
                return false;
            }
        }
        return s1[n-2] == s2[n-2] && s1[n-1] == s2[n-1];
    }
};

int main() {
    Solution solution;
    string s1 = "abcd";
    string s2 = "cdab";
    cout << solution.canBeEqual(s1, s2) << '\n';
    return 0;
}