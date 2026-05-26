// https://leetcode.cn/problems/count-the-number-of-special-characters-i/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int res = 0;
        unordered_set<char> letter(word.begin(), word.end());
        for (int i = 0; i < 26; ++i) {
            char ch = 'a' + i;
            res += (letter.count(ch) & letter.count(toupper(ch)));
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