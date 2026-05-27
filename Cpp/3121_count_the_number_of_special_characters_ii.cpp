// https://leetcode.cn/problems/count-the-number-of-special-characters-ii/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int res = 0;
        vector<bool> lowers(26, false), uppers(26, false);
        vector<bool> invalid(26, false);
        for (const char &ch: word) {
            if (invalid[tolower(ch) - 'a']) continue;
            if (islower(ch)) {
                int idx = ch - 'a';
                if (uppers[idx]) {
                    res -= lowers[idx];
                    invalid[idx] = true;
                }
                lowers[idx] = true;
            }
            else {
                int idx = ch - 'A';
                if (!uppers[idx]) {
                    res += lowers[idx];
                }
                uppers[idx] = true;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string word = "aaAbcBC";
    cout << sol.numberOfSpecialChars(word) << '\n';
    return 0;
}