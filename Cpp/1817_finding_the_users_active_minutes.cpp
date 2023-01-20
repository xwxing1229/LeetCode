// https://leetcode.cn/problems/finding-the-users-active-minutes/

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> cnt;
        for (vector<int>& log: logs) {
            cnt[log[0]].emplace(log[1]);
        }
        vector<int> res(k);
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            res[it->second.size() - 1] += 1;
        }
        return res;
    }
};
