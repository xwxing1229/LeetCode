// https://leetcode.cn/problems/weighted-word-mapping/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for (const auto &word: words) {
            int s = 0;
            for (const auto ch: word) {
                s += weights[ch - 'a'];
            }
            res += 'a' + 25 - s % 26;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"abcd","def","xyz"};
    vector<int> weights = {
        5,3,12,14,1,
        2,3,2,10,6,
        6,9,7,8,7,
        10,8,9,6,9,
        9,8,3,7,7,
        2
    };
    cout << sol.mapWordWeights(words, weights) << '\n';
    return 0;
}