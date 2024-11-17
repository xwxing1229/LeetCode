// https://leetcode.cn/problems/count-the-number-of-good-nodes/

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        graph_.resize(edges.size() + 1);
        for (auto &e: edges) {
            graph_[e[0]].push_back(e[1]);
            graph_[e[1]].push_back(e[0]);
        }
        res_ = 0;
        dfs(0, -1);
        return res_;
    }

    int dfs(int cur, int father) {
        int size = 0, total = 1;
        bool good = true;
        for (int node: graph_[cur]) {
            if (node == father) continue;
            int tmp = dfs(node, cur);
            if (size == 0) {
                size = tmp;
            }
            else if (size != tmp) {
                good = false;
            }
            total += tmp;
        }
        if (good) {
            res_ += 1;
        }
        return total;
    }

    vector<vector<int>> graph_;
    int res_;
};
