// https://leetcode.cn/problems/network-recovery-pathways/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> graph(n);
        int left = INT_MAX, right = 0;
        for (const auto &e: edges) {
            int u = e[0], v = e[1], c = e[2];
            if (online[u] && online[v]) {
                graph[u].push_back({v, c});
                left = min(left, c);
                right = max(right, c);
            }
        }

        auto check = [&](int score) -> bool {
            vector<long long> record(n, -1);
            record[n-1] = 0;
            auto dfs = [&](auto &&self, int u) -> long long {
                if (record[u] >= 0) return record[u];
                long long res = k + 1;
                for (const auto [v, c]: graph[u]) {
                    if (c >= score) {
                        res = min(res, self(self, v) + c);
                    }
                }
                record[u] = res;
                return res;
            };
            return dfs(dfs, 0) <= k;
        };

        int res = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid)) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {
        {0,1,5}, {1,3,10}, {0,2,3}, {2,3,4}
    };
    vector<bool> online = {true, true, true, true};
    long long k = 10;
    cout << sol.findMaxPathScore(edges, online, k) << '\n';
    return 0;
}