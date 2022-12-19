// https://leetcode.cn/problems/find-if-path-exists-in-graph/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (n == 1) return true;

        vector<vector<int>> graph(n);
        for (auto &edge: edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        queue<int> q;
        q.emplace(source);
        vector<int> visited(n);
        visited[source] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int node: graph[cur]) {
                if (node == destination) {
                    return true;
                }
                if (visited[node] < 1) {
                    q.emplace(node);
                    visited[node] = 1;
                }
            }
        }
        return false;
    }
};
