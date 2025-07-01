// https://leetcode.cn/problems/find-the-original-typed-string-i/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        word += ' ';
        int n = word.size(), start = 0;
        for (int i = 0; i < n; ++i) {
            if (word[i] != word[start]) {
                if (i - start > 1) {
                    res += i - start - 1;
                }
                start = i;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string word = "abbcccc";
    cout << sol.possibleStringCount(word) << '\n';
    return 0;
}