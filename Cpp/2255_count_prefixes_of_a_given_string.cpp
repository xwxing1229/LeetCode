// https://leetcode.cn/problems/count-prefixes-of-a-given-string/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = 0, n = s.size();
        for (auto &word: words) {
            if (word.size() <= n && word == s.substr(0, word.size())) {
                res += 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"a", "b", "c", "ab", "ac", "bc", "abc"};
    string s = "abc";
    cout << sol.countPrefixes(words, s) << '\n';
    return 0;
}