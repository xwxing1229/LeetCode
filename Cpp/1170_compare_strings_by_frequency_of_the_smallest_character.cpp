// https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character/

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        unordered_map<int, int> f_words;
        for (string word: words) {
            f_words[f(word)] += 1;
        }
        vector<int> res(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            int f_q = f(queries[i]);
            for (auto it = f_words.begin(); it != f_words.end(); ++it) {
                if (f_q < it->first) {
                    res[i] += it->second;
                }
            }
        }
        return res;
    }

    int f(string s) {
        vector<int> cnt(26, 0);
        for (char ch: s) {
            cnt[ch - 'a'] += 1;
        }
        for (int c: cnt) {
            if (c > 0) return c;
        }
        return 0;
    }
};
