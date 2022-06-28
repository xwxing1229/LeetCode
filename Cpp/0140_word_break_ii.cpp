// https://leetcode.cn/problems/word-break/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string sentence;
        backtrack(s, wordDict, sentence, 0);
        return res;
    }

private:
    void backtrack(string s, vector<string>& wordDict, string sentence, int idx) {
        if (idx == s.size()) {
            sentence.pop_back();
            res.push_back(sentence);
            return;
        }

        for (int length = 1; length <= s.size()-idx; ++length) {
            string sub = s.substr(idx, length);
            if (find(wordDict.begin(), wordDict.end(), sub) != wordDict.end()) {
                backtrack(s, wordDict, sentence+sub+" ", idx+length);
            }
        }
    }

    vector<string> res;
};
