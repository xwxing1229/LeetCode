// https://leetcode.cn/problems/largest-plus-sign/

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // dp[i][j][k]: number of consecutive 1 along the kth direction (left,
        // right, up, down) starting from (i,j).
        // Actually we only need min(dp[i][j][0], ..., dp[i][j][3]) for each (i,j).
        vector<vector<int>> dp(n, vector<int>(n,n));

        // unordered_set<int> s;
        // for (vector<int>& mine: mines) {
        //     s.emplace(n * mine[0] + mine[1]);
        // }
        // for (int i = 0; i < n; ++i) {
        //     int cnt = 0; // left
        //     for (int j = 0; j < n; ++j) {
        //         if (s.find(n * i + j) != s.end()) cnt = 0;
        //         else cnt += 1;
        //         if (cnt < dp[i][j]) dp[i][j] = cnt;
        //     }
        //     cnt = 0; // right
        //     for (int j = n-1; j >= 0; --j) {
        //         if (s.find(n * i + j) != s.end()) cnt = 0;
        //         else cnt += 1;
        //         if (cnt < dp[i][j]) dp[i][j] = cnt;
        //     }
        // }
        // for (int j = 0; j < n; ++j) {
        //     int cnt = 0; // up
        //     for (int i = 0; i < n; ++i) {
        //         if (s.find(n * i + j) != s.end()) cnt = 0;
        //         else cnt += 1;
        //         if (cnt < dp[i][j]) dp[i][j] = cnt;
        //     }
        //     cnt = 0; // down
        //     for (int i = n-1; i >= 0; --i) {
        //         if (s.find(n * i + j) != s.end()) cnt = 0;
        //         else cnt += 1;
        //         if (cnt < dp[i][j]) dp[i][j] = cnt;
        //     }
        // }

        // Here using a vector is faster than using an unordered set.
        vector<vector<int>> graph(n, vector<int>(n,1));
        for (vector<int>& mine: mines) {
            graph[mine[0]][mine[1]] = 0;
        }
        for (int i = 0; i < n; ++i) {
            int cnt = 0; // left
            for (int j = 0; j < n; ++j) {
                if (graph[i][j] == 0) cnt = 0;
                else cnt += 1;
                if (cnt < dp[i][j]) dp[i][j] = cnt;
            }
            cnt = 0; // right
            for (int j = n-1; j >= 0; --j) {
                if (graph[i][j] == 0) cnt = 0;
                else cnt += 1;
                if (cnt < dp[i][j]) dp[i][j] = cnt;
            }
        }
        for (int j = 0; j < n; ++j) {
            int cnt = 0; // up
            for (int i = 0; i < n; ++i) {
                if (graph[i][j] == 0) cnt = 0;
                else cnt += 1;
                if (cnt < dp[i][j]) dp[i][j] = cnt;
            }
            cnt = 0; // down
            for (int i = n-1; i >= 0; --i) {
                if (graph[i][j] == 0) cnt = 0;
                else cnt += 1;
                if (cnt < dp[i][j]) dp[i][j] = cnt;
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (res < dp[i][j]) res = dp[i][j];
            }
        }
        return res;
    }
};

