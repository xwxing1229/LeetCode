// https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-ii/
        
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
            if (rec.size() == 0) continue;
            sort(rec.begin(), rec.end(), greater<int>());
            res = max(res, rec[0]-2);
            if (rec.size() >= 2) {
                if (rec[0] == rec[1]) res = max(res, rec[0]-1);
                else res = max(res, rec[1]);
            }
            if (rec.size() >= 3) {
                res = max(res, rec[2]);
            }
        }
        return res > 0 ? res : -1;
    }
};
