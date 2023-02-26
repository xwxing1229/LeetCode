// https://leetcode.cn/problems/maximum-score-words-formed-by-letters/

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        words_ = words;
        for (char ch: letters) {
            cnt_[ch] += 1;
        }
        for (string word: words) {
            int s = 0;
            for (char ch: word) s += score[ch - 'a'];
            score_words_.push_back(s);
        }

        res_ = 0;
        dfs(0, 0);
        return res_;
    }

    void dfs(int idx, int score_cur) {
        for (int i = idx; i < words_.size(); ++i) {
            string word = words_[i];
            bool valid = true;
            unordered_map<char, int> cnt_word;
            for (char ch: word) cnt_word[ch] += 1;
            for (auto it = cnt_word.begin(); it != cnt_word.end(); ++it) {
                if (it->second > cnt_[it->first]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                for (auto it = cnt_word.begin(); it != cnt_word.end(); ++it) {
                    cnt_[it->first] -= it->second;
                }
                res_ = max(res_, score_cur + score_words_[i]);
                dfs(i+1, score_cur + score_words_[i]);
                for (auto it = cnt_word.begin(); it != cnt_word.end(); ++it) {
                    cnt_[it->first] += it->second;
                }
            }
        }
    }

    vector<string> words_;
    vector<int> score_words_;
    unordered_map<char, int> cnt_;

    int res_;
};
