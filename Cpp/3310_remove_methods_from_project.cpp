// https://leetcode.cn/problems/remove-methods-from-project/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> forward(n);
        for (const auto &invoc: invocations) {
            forward[invoc[0]].push_back(invoc[1]);
        }

        vector<bool> bugs(n, false);
        bugs[k] = true;
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (const int node: forward[curr]) {
                if (!bugs[node]) {
                    bugs[node] = true;
                    q.push(node);
                }
            }
        }

        vector<int> res;
        for (int curr = 0; curr < n; ++curr) {
            if (bugs[curr]) continue;
            for (const int node: forward[curr]) {
                if (bugs[node]) {
                    vector<int> tmp(n);
                    for (int i = 0; i < n; ++i) tmp[i] = i;
                    return tmp;
                }
            }
            res.push_back(curr);
        }
        return res;
    }
};