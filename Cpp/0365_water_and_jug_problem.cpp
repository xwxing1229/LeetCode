// https://leetcode.cn/problems/water-and-jug-problem/

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        auto hash_func = [](const pair<int,int> &p) {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        };
        unordered_set<pair<int,int>, decltype(hash_func)> seen(0, hash_func);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur.first == targetCapacity || cur.second == targetCapacity || cur.first + cur.second == targetCapacity) {
                return true;
            }
            if (seen.find(cur) != seen.end()) {
                continue;
            }
            seen.insert(cur);
            // Fill 1.
            q.push(make_pair(jug1Capacity, cur.second));
            // Fill 2.
            q.push(make_pair(cur.first, jug2Capacity));
            // Empty 1.
            q.push(make_pair(0, cur.second));
            // Empty 2.
            q.push(make_pair(cur.first, 0));
            // Put the water in 1 to 2 until 1 is empty or 2 is full.
            q.push(make_pair(cur.first-min(cur.first, jug2Capacity-cur.second),
                             cur.second+min(cur.first, jug2Capacity-cur.second)));
            // Put the water in 2 to 1 until 2 is empty or 1 is full.
            q.push(make_pair(cur.first+min(cur.second, jug1Capacity-cur.first),
                             cur.second-min(cur.second, jug1Capacity-cur.first)));
        }
        return false;
    }
};
