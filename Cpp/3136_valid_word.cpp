// https://leetcode.cn/problems/valid-word/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
        string special = "@#$";
        string vowel = "aeiouAEIOU";
        bool valid_vowel = false, valid_con = false;
        for (const auto ch: word) {
            if (special.find(ch) != special.npos) return false;
            else if (isdigit(ch)) continue;
            else if (vowel.find(ch) != special.npos) valid_vowel = true;
            else valid_con = true;
        }
        return valid_vowel && valid_con;
    }
};

int main() {
    Solution sol;
    string word = "abc123";
    cout << sol.isValid(word) << '\n';
    return 0;
}