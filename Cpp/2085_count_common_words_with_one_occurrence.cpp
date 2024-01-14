// https://leetcode.cn/problems/count-common-words-with-one-occurrence/

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> cnt1, cnt2;
        for (auto &word: words1) {
            cnt1[word] += 1;
        }
        for (auto &word: words2) {
            cnt2[word] += 1;
        }
        int res = 0;
        for (auto it = cnt1.begin(); it != cnt1.end(); ++it) {
            if (it->second == 1 && cnt2[it->first] == 1) {
                res += 1;
            }
        }
        return res;
    }
};
