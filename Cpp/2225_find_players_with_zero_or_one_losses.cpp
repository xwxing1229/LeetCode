// https://leetcode.cn/problems/find-players-with-zero-or-one-losses/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> winners, losers;
        for (auto &m: matches) {
            winners[m[0]] += 1;
            losers[m[1]] += 1;
        }
        vector<vector<int>> res(2);
        for (auto it = winners.begin(); it != winners.end(); ++it) {
            if (losers.find(it->first) == losers.end()) {
                res[0].push_back(it->first);
            }
        }
        for (auto it = losers.begin(); it != losers.end(); ++it) {
            if (it->second == 1) {
                res[1].push_back(it->first);
            }
        }
        for (int i = 0; i < 2; ++i) {
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};
