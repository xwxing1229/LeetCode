// https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-i/
        
class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> record(26, vector<int>());
        char pre = s[0];
        int pre_id = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != pre) {
                record[pre - 'a'].push_back(i - pre_id);
                pre = s[i];
                pre_id = i;
            }
        }
        record[pre - 'a'].push_back(s.size() - pre_id);

        int res = -1;
        for (auto &rec: record) {
            unordered_map<int, int> cnts;
            for (int n: rec) {
                for (int length = 1; length <= n; ++length) {
                    cnts[length] += n + 1 - length;
                    if (cnts[length] >= 3 && length > res) {
                        res = length;
                    }
                }
            }
        }
        return res;
    }
};
