// https://leetcode.cn/problems/avoid-flood-in-the-city/

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, 1);
        set<int> drydays;
        unordered_map<int, int> fulllakes;
        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            if (rains[i] == 0) {
                drydays.insert(i);
            }
            else {
                res[i] = -1;
                if (fulllakes.find(lake) != fulllakes.end()) {
                    auto it = drydays.upper_bound(fulllakes[lake]);
                    if (it == drydays.end()) {
                        return (vector<int>){};
                    }
                    res[*it] = lake;
                    drydays.erase(it);
                }
                fulllakes[lake] = i;
            }
        }
        return res;
    }
};
