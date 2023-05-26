// https://leetcode.cn/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        vector<pair<int,int>> dirs = {
            {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}
        };

        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, 0));
        unordered_map<int, int> cost_till_now;
        cost_till_now[0] = 0;
        // come_from[n1] = n2 indicates a path n2 -> n1.
        unordered_map<int, int> come_from;

        bool find = false;
        int goal = n*n-1;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int cur_i = cur.second / n, cur_j = cur.second % n;
            if (cur.second == goal) {
                find = true;
                break;
            }

            for (auto d: dirs) {
                int i = cur_i + d.first, j = cur_j + d.second;
                if (i < 0 || i >= n || j < 0 || j >= n) continue;
                if (grid[i][j] == 1) continue;
                // +1 because moves in all directions have same costs.
                int cost_to_neighbor = cost_till_now[cur.second] + 1;
                int neighbor_idx = i * n + j;
                if (cost_till_now.find(neighbor_idx) == cost_till_now.end() ||
                    cost_till_now[neighbor_idx] > cost_to_neighbor) {
                    cost_till_now[neighbor_idx] = cost_to_neighbor;
                    come_from[neighbor_idx] = cur.second;
                    int cost = cost_to_neighbor + heuristicCost(i, j, n);
                    pq.push(make_pair(-cost, neighbor_idx));
                }
            }
        }

        if (!find) return -1;
        int res = 1, cur = goal;
        while (cur != 0) {
            res += 1;
            cur = come_from[cur];
        }
        return res;
    }

    int heuristicCost(int i, int j, int n) {
        // The heuristic cost should be designed to be consistent with the problem to
        // find a SHORTEST path.
        // In this problem, moves in all directions have same costs.
        return max(n-1-i, n-1-j);
    }
};