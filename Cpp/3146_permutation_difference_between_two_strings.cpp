// https://leetcode.cn/problems/permutation-difference-between-two-strings/

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> idxs;
        for (int i = 0; i < s.size(); ++i) {
            idxs[s[i]] = i;
        }
        int res = 0;
        for (int i = 0; i < t.size(); ++i) {
            res += abs(i - idxs[t[i]]);
        }
        return res;
    }
};
