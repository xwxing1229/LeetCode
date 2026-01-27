// https://leetcode.cn/problems/minimum-cost-path-with-edge-reversals/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        using PII = pair<int, int>;

        vector<vector<PII>> graph(n);
        for (const auto &e: edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w+w});
        }

        vector<int> dist(n, -1);
        dist[0] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({0, 0}); // cost, node
        while (!pq.empty()) {
            auto [d_cur, cur] = pq.top();
            pq.pop();
            if (dist[cur] >= 0 && d_cur > dist[cur]) {
                continue;
            }
            if (cur == n-1) {
                return d_cur;
            }
            for (const auto &[next, w]: graph[cur]) {
                int d_next = d_cur + w;
                if (dist[next] < 0 || dist[next] > d_next) {
                    dist[next] = d_next;
                    pq.push({d_next, next});
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {
        {0,1,3},
        {3,1,1},
        {2,3,4},
        {0,2,2}
    };
    cout << sol.minCost(n, edges) << '\n';
    return 0;
}