// https://leetcode.cn/problems/maximum-average-pass-ratio/

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double res = 0;
        priority_queue<tuple<double, int, int>> pq;
        for (auto &cl: classes) {
            int p = cl[0], t = cl[1];
            res += (double) p / t;

            double incre = (double) (p+1) / (t+1) - (double) p / t;
            pq.push({incre, p, t});
            
        }
        for (int i = 0; i < extraStudents; ++i) {
            auto [incre, p, t] = pq.top();
            pq.pop();
            res += incre;

            incre = (double) (p+2) / (t+2) - (double) (p+1) / (t+1);
            pq.push({incre, p+1, t+1});
        }
        res /= pq.size();
        return res;
    }
};
