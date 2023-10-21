// https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        long long res = 0;
        vector<bool> visited(n, false);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            q.push(i);
            visited[i] = true;
            long long cnt = 1;
            while (!q.empty()) {
                int a = q.front();
                q.pop();
                for (int b: graph[a]) {
                    if (!visited[b]) {
                        q.push(b);
                        visited[b] = true;
                        cnt += 1;
                    }
                }
            }
            res += cnt * (n - cnt);
        }
        return res/2;
    }
};
