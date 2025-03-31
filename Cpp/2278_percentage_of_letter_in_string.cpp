// https://leetcode.cn/problems/percentage-of-letter-in-string/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size(), cnt = 0;
        for (char &ch: s) {
            cnt += ch == letter;
        }
        return cnt * 100 / n;
    }
};

int main() {
    Solution sol;
    string s = "foobar";
    char letter = 'o';
    cout << sol.percentageLetter(s, letter) << '\n';
    return 0;
}