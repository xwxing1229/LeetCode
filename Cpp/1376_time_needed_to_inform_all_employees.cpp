// https://leetcode.cn/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; ++i) {
            graph[manager[i]].push_back(i);
        }

        int res = 0;
        queue<int> q;
        q.push(headID);
        vector<int> minutes(n, 0);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                int cur = q.front();
                q.pop();
                for (int employee: graph[cur]) {
                    q.push(employee);
                    minutes[employee] = minutes[cur] + informTime[cur];
                    if (res < minutes[employee]) {
                        res = minutes[employee];
                    }
                }
            }
        }
        return res;
    }
};
