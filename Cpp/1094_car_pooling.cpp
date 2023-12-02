// https://leetcode.cn/problems/car-pooling/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int> &t1, const vector<int> &t2) {
            return t1[1] < t2[1];
        });
        int cur = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i < trips.size(); ++i) {
            while (!pq.empty() && pq.top().first <= trips[i][1]) {
                cur -= trips[pq.top().second][0];
                pq.pop();
            }
            cur += trips[i][0];
            if (cur > capacity) {
                return false;
            }
            pq.push(make_pair(trips[i][2], i));
        }
        return true;
    }
};
