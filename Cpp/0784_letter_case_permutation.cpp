// https://leetcode.cn/problems/letter-case-permutation/

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        queue<string> q;
        string pre = "";
        q.push(pre);
        for (char ch: s) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                pre = q.front();
                q.pop();
                string tmp = pre + ch;
                q.push(tmp);
                if (!isdigit(ch)) {
                    tmp = pre + flipCase(ch);
                    q.push(tmp);
                } 
            }
        }

        vector<string> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }

    char flipCase(char ch) {
        if (isupper(ch)) {
            return tolower(ch);
        }
        else {
            return toupper(ch);
        }
    }
};
