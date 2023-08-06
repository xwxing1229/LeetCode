// https://leetcode.cn/problems/max-value-of-equation/

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // Use a priority queue to save the indices such that
        // points[pq.top()][1] - points[pq.top()][0] >= points[k][1] - points[k][0]
        // for any k in pq.
        auto comp = [&](int i, int j) {
            return points[i][1] - points[i][0] < points[j][1] - points[j][0];
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        int res = 0;
        bool start = false;
        for (int j = 0; j < points.size(); ++j) {
            while (!pq.empty() && points[j][0] - points[pq.top()][0] > k) {
                pq.pop();
            }
            if (!pq.empty()) {
                int i = pq.top();
                int tmp = points[j][0] + points[j][1] + points[i][1] - points[i][0];
                if (!start || res < tmp) {
                    res = tmp;
                    start = true;
                }
            }
            pq.push(j);
        }
        return res;
    }
};
