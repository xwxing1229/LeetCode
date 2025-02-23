// https://leetcode.cn/problems/count-pairs-of-similar-strings/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int res = 0;
        unordered_map<int, int> cnts;
        for (auto &word: words) {
            int val = 0;
            for (char ch: word) {
                val |= (1 << (ch - 'a'));
            }
            res += cnts[val];
            cnts[val] += 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"aabb", "ab", "ba"};
    cout << sol.similarPairs(words) << '\n';
    return 0;
}