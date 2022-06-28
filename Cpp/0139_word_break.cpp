// https://leetcode.cn/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        backtrack(s, wordDict, 0);
        return res;
    }

private:
    void backtrack(string s, vector<string>& wordDict, int idx) {
        if (idx == s.size()) {
            res = true;
            return;
        }

        for (string word: wordDict) {
            if (res) {
                return;
            }
            
            int length = word.size();
            string sub = s.substr(0, idx+length);
            if ((!word.compare(s.substr(idx, length))) &&
                (find(memory.begin(), memory.end(), sub) == memory.end())) {
                memory.push_back(sub);
                backtrack(s, wordDict, idx+length);
            }
        }
    }

    bool res = false;

    vector<string> memory;
};
