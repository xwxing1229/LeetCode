// https://leetcode.cn/problems/filter-restaurants-by-vegan-friendly-price-and-distance/

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int,int>> filtered;
        for (auto &r: restaurants) {
            if (r[2] < veganFriendly) continue;
            if (r[3] > maxPrice) continue;
            if (r[4] > maxDistance) continue;
            filtered.push_back(make_pair(r[0], r[1]));
        }
        sort(filtered.begin(), filtered.end(), [](const pair<int,int> &p1, const pair<int,int> &p2) {
            return p1.second > p2.second || (p1.second == p2.second && p1.first > p2.first);
        });
        vector<int> res;
        for (auto &r: filtered) {
            res.push_back(r.first);
        }
        return res;
    }
};
