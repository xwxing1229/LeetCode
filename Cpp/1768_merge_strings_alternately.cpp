// https://leetcode.cn/problems/merge-strings-alternately/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int idx1 = 0, idx2 = 0;
        string res = "";
        while ((idx1 < n1) && (idx2 < n2)) {
            res += word1[idx1];
            res += word2[idx2];
            idx1 += 1;
            idx2 += 1;
        }
        if (idx1 < n1) {
            res += word1.substr(idx1, n1-idx1);
        }
        if (idx2 < n2) {
            res += word2.substr(idx2, n2-idx2);
        }
        return res;
    }
};
