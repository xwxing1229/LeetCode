// https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        /* Unordered_set is not necessary.
        vector<string> res;
        sort(folder.begin(), folder.end());
        unordered_set<string> check_sub;
        for (auto f: folder) {
            bool is_sub = false;
            for (int i = 0; i < f.size(); ++i) {
                if ((i + 1 < f.size() && f[i+1] == '/') || (i + 1 == f.size())) {
                    string tmp = f.substr(0, i+1);
                    if (check_sub.find(tmp) != check_sub.end()) {
                        is_sub = true;
                        break;
                    }
                }
            }
            if (!is_sub) {
                res.push_back(f);
                check_sub.emplace(f);
            }
        }
        */

        sort(folder.begin(), folder.end());
        vector<string> res = {folder[0]};
        for (int i = 1; i < folder.size(); ++i) {
            string pre = res.back(), cur = folder[i];
            int n_pre = pre.size(), n_cur = cur.size();
            if (n_pre > n_cur) {
                res.push_back(cur);
            }
            else if (n_pre == n_cur) {
                if (pre != cur) {
                    res.push_back(cur);
                }
            }
            else {
                if (!(pre == cur.substr(0, n_pre) && cur[n_pre] == '/')) {
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
};
