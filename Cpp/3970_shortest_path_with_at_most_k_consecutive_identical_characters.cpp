// https://leetcode.cn/problems/shortest-path-with-at-most-k-consecutive-identical-characters/

#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto &e: edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        // pq = {(d, u, cnt)}
        // d: distance from 0 to u with cnt consecutive identical chars
        //    at the end of str path
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push(make_tuple(0, 0, 1));
        // dist[u][cnt]: min distance from 0 to u with cnt consecutive identical chars
        //               at the end of str path
        vector<vector<int>> dist(n, vector<int>(k+1, -1));
        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();
            if (u == n-1) {
                return d;
            }
            if (dist[u][cnt] >= 0 && d > dist[u][cnt]) {
                continue;
            }
            for (const auto vw: graph[u]) {
                int v = vw.first, w = vw.second;
                int cnt_v = labels[u] == labels[v] ? cnt + 1 : 1;
                int d_v = d + w;
                if (cnt_v <= k && (dist[v][cnt_v] < 0 || d_v < dist[v][cnt_v])) {
                    pq.push(make_tuple(d_v, v, cnt_v));
                    dist[v][cnt_v] = d_v;
                }
            }
        }
        return -1;
    }
};