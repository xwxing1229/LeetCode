// https://leetcode.cn/problems/check-if-two-string-arrays-are-equivalent/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int idx1 = 0, idx2 = 0;
        int i1 = 0, i2 = 0;
        while ((idx1 < word1.size()) && (idx2 < word2.size())) {
            while ((i1 < word1[idx1].size()) && (i2 < word2[idx2].size())) {
                if (word1[idx1][i1] != word2[idx2][i2]) {
                    return false;
                }
                i1 += 1;
                i2 += 1;
            }
            if (i1 == word1[idx1].size()) {
                i1 = 0;
                idx1 += 1;
            }
            if (i2 == word2[idx2].size()) {
                i2 = 0;
                idx2 += 1;
            }
        }
        if ((idx1 != word1.size()) || (idx2 != word2.size())) {
            return false;
        }
        return true;
    }
};
