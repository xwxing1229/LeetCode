// https://leetcode.cn/problems/the-employee-that-worked-on-the-longest-task/

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int res = logs[0][0], spend = logs[0][1];
        for (int i = 1; i < logs.size(); ++i) {
            int res_tmp = logs[i][0], spend_tmp = logs[i][1] - logs[i-1][1];
            if (spend_tmp > spend) {
                res = res_tmp;
                spend = spend_tmp;
            }
            else if (spend_tmp == spend && res_tmp < res) {
                res = res_tmp;
            }
        }
        return res;
    }
};
