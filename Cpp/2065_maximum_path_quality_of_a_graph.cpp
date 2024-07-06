// https://leetcode.cn/problems/maximum-path-quality-of-a-graph/

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        maxTime_ = maxTime;
        values_ = values;
        int n = values.size();
        graph_.resize(n);
        for (auto &e: edges) {
            graph_[e[0]].push_back(make_pair(e[1], e[2]));
            graph_[e[1]].push_back(make_pair(e[0], e[2]));
        }

        res_ = 0;
        vector<int> visited(n, 0);
        visited[0] = 1;
        dfs(0, values[0], 0, visited);
        return res_;
    }

    void dfs(int cur, int val, int t, vector<int> &visited) {
        if (cur == 0 && t <= maxTime_) res_ = max(res_, val);
        for (auto &p: graph_[cur]) {
            int tused = t + p.second;
            if (tused > maxTime_) continue;
            if (visited[p.first] == 1) {
                dfs(p.first, val, tused, visited);
            }
            else {
                visited[p.first] = 1;
                dfs(p.first, val+values_[p.first], tused, visited);
                visited[p.first] = 0;
            }
        }
    }

    int maxTime_;
    vector<int> values_;
    vector<vector<pair<int, int>>> graph_;
    int res_;
};
