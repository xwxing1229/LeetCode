// https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        unordered_set<long> pairs;
        for (auto &edge: connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            pairs.insert((long)edge[0] * n + edge[1]);
        }
        int res = 0;
        queue<int> q;
        q.push(0);
        vector<int> visited(n, 0);
        visited[0] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto node: graph[cur]) {
                if (visited[node]) {
                    continue;
                }
                if (pairs.find((long)node * n + cur) == pairs.end()) {
                    res += 1;
                }
                q.push(node);
                visited[node] = 1;
            }
        }
        return res;
    }
};
