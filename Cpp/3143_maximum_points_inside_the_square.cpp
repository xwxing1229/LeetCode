// https://leetcode.cn/problems/maximum-points-inside-the-square/

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        map<int, vector<int>> m;
        for (int i = 0; i < points.size(); ++i) {
            int d = max(abs(points[i][0]), abs(points[i][1]));
            m[d].push_back(i);
        }
        vector<int> visited(26, 0);
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            auto idxs = it->second;
            for (int i: idxs) {
                int ord = s[i] - 'a';
                if (visited[ord]) {
                    return res;
                }
                visited[ord] = 1;
            }
            res += idxs.size();
        }
        return res;
    }
};
