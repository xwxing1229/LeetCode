// https://leetcode-cn.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first = strs[0];
        int len_first = first.size();
        int len_strs = strs.size();

        for (int i = 0; i < len_first; ++i) {
            char c = first[i];

            for (int j = 1; j < len_strs; ++j) {
                if ((i == strs[j].size()) || (c != strs[j][i])) {
                    return first.substr(0, i);
                }
            }
        }
        return first;
    }
};