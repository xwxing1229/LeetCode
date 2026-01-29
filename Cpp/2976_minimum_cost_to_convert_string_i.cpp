// https://leetcode.cn/problems/minimum-cost-to-convert-string-i/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        using PII = pair<int, int>;

        vector<vector<int>> graph(26, vector<int>(26, -1));
        for (int i = 0; i < original.size(); ++i) {
            int node0 = original[i] - 'a';
            int node1 = changed[i] - 'a';
            if (graph[node0][node1] < 0 || graph[node0][node1] > cost[i]) {
                graph[original[i]-'a'][changed[i]-'a'] = cost[i];
            }
        }
        vector<vector<int>> cost_min(26, vector<int>(26, INT_MAX));
        for (int node = 0; node < 26; ++node) {
            cost_min[node][node] = 0;
        }

        auto updateCostMin = [&](int node) {
            priority_queue<PII, vector<PII>, greater<PII>> pq;
            pq.push({0, node});
            while (!pq.empty()) {
                auto [c_curr, curr] = pq.top();
                pq.pop();
                if (cost_min[node][curr] < c_curr) {
                    continue;
                }
                cost_min[node][curr] = c_curr;
                for (int next = 0; next < 26; ++next) {
                    if (graph[curr][next] < 0) {
                        continue;
                    }
                    int c_next = c_curr + graph[curr][next];
                    if (cost_min[node][next] > c_next) {
                        cost_min[node][next] = c_next;
                        pq.push({c_next, next});
                    }
                }
            }
        };
        for (int node = 0; node < 26; ++node) {
            updateCostMin(node);
        }

        long long res = 0;
        for (int i = 0; i < source.size(); ++i) {
            int c = cost_min[source[i]-'a'][target[i]-'a'];
            if (c == INT_MAX) {
                return -1;
            }
            res += c;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string source = "abcd";
    string target = "acbe";
    vector<char> original = {'a','b','c','c','e','d'};
    vector<char> changed = {'b','c','b','e','b','e'};
    vector<int> cost = {2,5,5,1,2,20};
    cout << sol.minimumCost(source, target, original, changed, cost) << '\n';
    return 0;
}