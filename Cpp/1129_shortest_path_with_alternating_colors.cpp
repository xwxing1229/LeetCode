// https://leetcode.cn/problems/shortest-path-with-alternating-colors/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> graph(2, vector<vector<int>>(n)); // 0 for red, 1 for blue
        for (auto edge: redEdges) {
            graph[0][edge[0]].push_back(edge[1]);
        }
        for (auto edge: blueEdges) {
            graph[1][edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> dist(2, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        dist[0][0] = 0;
        dist[1][0] = 0;
        q.push(make_pair(0, 0));
        q.push(make_pair(0, 1));
        while (!q.empty()) {
            int x = q.front().first, color = q.front().second;
            q.pop();
            for (int y: graph[1-color][x]) {
                if (dist[1-color][y] != INT_MAX) {
                    continue;
                }
                dist[1-color][y] = dist[color][x] + 1;
                q.push(make_pair(y, 1-color));
            }
        }
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = min(dist[0][i], dist[1][i]);
            if (res[i] == INT_MAX) {
                res[i] = -1;
            }
        }
        return res;

    }
};
