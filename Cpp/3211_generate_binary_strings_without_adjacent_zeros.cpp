// https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros/

class Solution {
public:
    vector<string> validStrings(int n) {
        n_ = n;
        dfs(0, "");
        return res_;
    }

    void dfs(int idx, string cur) {
        if (idx == n_) {
            res_.push_back(cur);
            return;
        }

        if (cur.empty() || cur.back() == '1') {
            dfs(idx+1, cur+'1');
            dfs(idx+1, cur+'0');
        }
        else {
            dfs(idx+1, cur+'1');
        }
    }

    vector<string> res_;
    int n_;
};
