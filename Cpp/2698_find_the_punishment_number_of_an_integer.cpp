// https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/
        
class Solution {
public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int num = 1; num <= n; ++num) {
            int sq = num * num;
            if (dfs(to_string(sq), num, -1, 0)) {
                res += sq;
            }
        }
        return res;
    }

    bool dfs(string s, int num, int idx, int cur) {
        // if (cur > num) return false;
        // else if (idx == s.size()-1 && cur == num) return true;
        
        if (idx == s.size()-1 && cur == num) return true;

        for (int i = idx+1; i < s.size(); ++i) {
            int cur_new = cur + stoi(s.substr(idx+1, i-idx));
            if (dfs(s, num, i, cur_new)) return true;
            else if (cur_new > num) break;
        }
        return false;
    }
};