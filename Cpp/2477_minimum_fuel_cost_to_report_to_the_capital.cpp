// https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int, vector<int>> graph;
        for (auto &edge: roads) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        long long res = 0;
        function<int(int, int)> dfs = [&](int cur, int parent) -> int {
            int total = 1;
            for (auto node: graph[cur]) {
                if (node != parent) {
                    int people = dfs(node, cur);
                    res += (people + seats - 1) / seats;
                    total += people;
                }
            }
            return total;
        };
        dfs(0, -1);
        return res;
    }
};