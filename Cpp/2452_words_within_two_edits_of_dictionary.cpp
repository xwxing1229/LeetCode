// https://leetcode.cn/problems/words-within-two-edits-of-dictionary/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        auto CheckValid = [](const string &query, const string &word) {
            int cnt = 0;
            for (int i = 0; i < query.size(); ++i) {
                cnt += (query[i] != word[i]);
            }
            return cnt <= 2;
        };

        vector<string> res;
        res.reserve(queries.size());
        for (const string &q: queries) {
            for (const string &word: dictionary) {
                if (CheckValid(q, word)) {
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> queries = {"word","note","ants","wood"};
    vector<string> dictionary = {"wood","joke","moat"};
    auto res = sol.twoEditWords(queries, dictionary);
    for (const string &q: res) cout << q << ", ";
    cout << '\n';
    return 0;
}