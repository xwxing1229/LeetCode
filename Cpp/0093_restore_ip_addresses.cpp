// https://leetcode.cn/problems/restore-ip-addresses/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> tmp_idx;
        backtrack(s, tmp_idx, 1);
        return res;
    }

private:
    vector<string> res;

    void backtrack(string s, vector<int> &tmp_idx, int idx) {
        if (tmp_idx.size() == 3) {
            if (check_valid(s, tmp_idx)) {
                string ss(s);
                for (int i = 2; i >= 0; --i) {
                    ss.insert(ss.begin()+tmp_idx[i], '.');
                }
                res.push_back(ss);
            return;
            }
        }

        for (int i = idx; i < s.size(); ++i) {
            tmp_idx.push_back(i);
            backtrack(s, tmp_idx, i+1);
            tmp_idx.pop_back();
        }
    }

    bool check_valid(string s, vector<int> tmp_idx) {
        tmp_idx.insert(tmp_idx.begin(), 0);
        tmp_idx.push_back(s.size());
        for (int i = 0; i < 4; ++i) {
            string sp = s.substr(tmp_idx[i], tmp_idx[i+1] - tmp_idx[i]);

            if ((sp.size() > 3) || ((sp.size() > 1) && (sp[0] == '0'))) {
                return false;
            }

            int val = stoi(sp);
            if (val > 255) {
                return false;
            }
        }
        return true;
    }
};
