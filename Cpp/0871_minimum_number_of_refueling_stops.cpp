// https://leetcode.cn/problems/minimum-number-of-refueling-stops/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int res = 0;
        int pos_pre = 0;
        int cur = startFuel;
        stations.push_back((vector<int>){target, 0});
        priority_queue<int> pq;
        for (auto station: stations) {
            int pos = station[0], fuel = station[1];
            cur -= pos - pos_pre;
            while (!pq.empty() && cur < 0) {
                cur += pq.top();
                pq.pop();
                res += 1;
            }
            if (cur < 0) {
                return -1;
            }
            pq.push(fuel);
            pos_pre = pos;
        }
        return res;
    }
};
