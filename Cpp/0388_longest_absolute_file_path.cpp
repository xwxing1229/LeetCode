// https://leetcode.cn/problems/longest-absolute-file-path/

class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        unordered_map<int, int> cnt {{-1, 0}};
        vector<string> sp = split(input, '\n');
        for (string line: sp) {
            int depth = count(line.begin(), line.end(), '\t');
            cnt[depth] = cnt[depth-1] + line.size() - depth;

            if (count(line.begin(), line.end(), '.') > 0) {
                res = max(res, cnt[depth] + depth);
            }
        }
        return res;
    }

private:
    vector<string> split(string input, char deli) {
        vector<string> res;
        string tmp;
        for (char ch: input) {
            if (ch == deli) {
                res.push_back(tmp);
                tmp.clear();
            }
            else {
                tmp = tmp + ch;
            }
        }
        if (input[input.size()-1] != deli) {
            res.push_back(tmp);
        }
        return res;
    }
};
