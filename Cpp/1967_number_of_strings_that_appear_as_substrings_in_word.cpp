// https://leetcode.cn/problems/number-of-strings-that-appear-as-substrings-in-word/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (const string &p: patterns) {
            res += word.find(p) != string::npos;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> patterns = {"a","abc","bc","d"};
    string word = "abc";
    cout << sol.numOfStrings(patterns, word) << '\n';
    return 0;
}