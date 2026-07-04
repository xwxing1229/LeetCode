// https://leetcode.cn/problems/minimum-score-of-a-path-between-two-cities/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n+1);
        vector<int> distance(n+1, 1e5+1);
        for (const auto &r: roads) {
            int a = r[0], b = r[1], d = r[2];
            graph[a].push_back(b);
            graph[b].push_back(a);
            distance[a] = min(distance[a], d);
            distance[b] = min(distance[b], d);
        }

        int res = distance[1];
        vector<bool> connect(n+1, false);
        connect[1] = true;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            for (int b: graph[a]) {
                if (!connect[b]) {
                    res = min(res, distance[b]);
                    connect[b] = true;
                    q.push(b);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> roads = {
        {1,2,9}, {2,3,6}, {2,4,5}, {1,4,7}
    };
    cout << sol.minScore(n, roads) << '\n';
    return 0;
}