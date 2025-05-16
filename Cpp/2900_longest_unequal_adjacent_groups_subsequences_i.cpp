// https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-i/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
        
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res = {words[0]};
        int pre = groups[0];
        for (int i = 1; i < groups.size(); ++i) {
            if (groups[i] != pre) {
                res.push_back(words[i]);
                pre = groups[i];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"e", "a", "b"};
    vector<int> groups = {0, 0, 1};
    auto res = sol.getLongestSubsequence(words, groups);
    for (auto &s: res) {
        cout << s << ", ";
    }
    cout << '\n';
    return 0;
}