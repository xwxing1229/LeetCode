// https://leetcode.cn/problems/detonate-the-maximum-bombs/

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i) {
            int xa = bombs[i][0], ya = bombs[i][1], ra = bombs[i][2];
            for (int j = i+1; j < n; ++j) {
                int xb = bombs[j][0], yb = bombs[j][1], rb = bombs[j][2];
                long dsq = ((long)xb-xa)*(xb-xa) + ((long)yb-ya)*(yb-ya);
                if (dsq <= (long)ra*ra) {
                    graph[i].push_back(j);
                }
                if (dsq <= (long)rb*rb) {
                    graph[j].push_back(i);
                }
            }
        }

        int res = 1;
        for (int i = 0; i < n; ++i) {
            int tmp = 1;
            queue<int> q;
            q.push(i);
            vector<int> visited(n, 0);
            visited[i] = 1;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int node: graph[cur]) {
                    if (visited[node] == 0) {
                        tmp += 1;
                        q.push(node);
                        visited[node] = 1;
                    }
                }
            }
            res = max(res, tmp);
        }
        return res;
    }
};
