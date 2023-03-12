// https://leetcode.cn/problems/count-subtrees-with-max-distance-between-cities/

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        for (auto &edge: edges) {
            graph_[edge[0]-1].push_back(edge[1]-1);
            graph_[edge[1]-1].push_back(edge[0]-1);
        }
        res_ = vector<int>(n-1);
        for (int mask = 3; mask < (1 << n); ++mask) {
            if ((mask & (mask-1)) == 0) continue;
            // Choose a start node.
            int start = 0;
            while (((mask >> start) & 1) == 0) {
                start += 1;
            }
            // If the current mask is valid, change the start node and compute the diameter.
            if (bfs(start, mask, false)) {
                bfs(start, mask, true);
            }
        }
        return res_;
    }

    bool bfs(int &start, int mask, bool update) {
        queue<int> q;
        q.push(start);
        mask ^= (1 << start);
        int dist = -1;
        while (!q.empty()) {
            dist += 1;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto cur = q.front();
                q.pop();
                start = cur;
                for (auto neigh: graph_[cur]) {
                    if ((mask >> neigh) & 1) {
                        q.push(neigh);
                        mask ^= (1 << neigh);
                    }
                }
            }
        }
        if (mask == 0) {
            if (update) res_[dist-1] += 1;
            return true;
        }
        else return false;
    }

    unordered_map<int, vector<int>> graph_;
    vector<int> res_;
};
