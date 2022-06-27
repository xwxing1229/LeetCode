// https://leetcode.cn/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        backtrack(s, tmp, 0);
        return res;
    }

private:
    void backtrack(string s, vector<string> &tmp, int idx) {
        if (idx == s.size()) {
            res.push_back(tmp);
            return;
        }

        for (int length = 1; length < s.size()-idx+1; ++length) {
            string substr = s.substr(idx, length);
            if (isValid(substr)) {
                tmp.push_back(substr);
                backtrack(s, tmp, idx+length);
                tmp.pop_back();
            }
        }
    }

    bool isValid(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i = i + 1;
                j = j - 1;
            }
            else {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> res;
};
