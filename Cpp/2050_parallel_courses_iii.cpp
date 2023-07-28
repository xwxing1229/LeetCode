// https://leetcode.cn/problems/parallel-courses-iii/

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> prerequisite(n);
        for (auto &relation: relations) {
            prerequisite[relation[1]-1].push_back(relation[0]-1);
        }

        vector<int> check(n, 0);
        function<int(int)> dfs = [&](int cur) {
            if (check[cur] > 0) {
                return check[cur];
            }

            int tmp = 0;
            for (int course: prerequisite[cur]) {
                tmp = max(tmp, dfs(course));
            }
            check[cur] = tmp + time[cur];
            return check[cur];
        };

        int res = 0;
        for (int course = 0; course < n; ++course) {
            res = max(res, dfs(course));
        }
        return res;
    }
};