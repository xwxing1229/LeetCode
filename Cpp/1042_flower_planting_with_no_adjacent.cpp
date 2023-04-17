// https://leetcode.cn/problems/flower-planting-with-no-adjacent/

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);
        for (auto &path: paths) {
            graph[path[0]-1].push_back(path[1]-1);
            graph[path[1]-1].push_back(path[0]-1);
        }
        vector<int> res(n, 1);
        vector<vector<int>> valid(n, vector<int>(4, 1));
        for (int i = 0; i < n; ++i) {
            for (int garden = 0; garden < 4; ++garden) {
                if (valid[i][garden]) {
                    res[i] = garden + 1;
                    for (auto j: graph[i]) {
                        valid[j][garden] = 0;
                    }
                    break;
                }
            }
        }
        return res;
    }
};
