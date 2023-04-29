// https://leetcode.cn/problems/longest-string-chain/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &s1, const string &s2) {
            return s1.size() < s2.size();
        });
        unordered_map<string, int> cnt;
        int res = 0;
        for (string &word: words) {
            cnt[word] = 1;
            for (int i = 0; i < word.size(); ++i) {
                string pre = word.substr(0, i) + word.substr(i+1);
                if (cnt.find(pre) != cnt.end()) {
                    int tmp = cnt[pre] + 1;
                    if (tmp > cnt[word]) {
                        cnt[word] = tmp;
                    }
                }
            }
            if (cnt[word] > res) {
                res = cnt[word];
            }
        }
        return res;
    }
};
