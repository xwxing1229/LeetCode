// https://leetcode.cn/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> judge(n+1, 1), cnts(n+1, 0);
        for (auto &p: trust) {
            judge[p[0]] = 0;
            cnts[p[1]] += 1;
        }
        for (int i = 1; i < n+1; ++i) {
            if (judge[i] == 1 && cnts[i] == n-1) {
                return i;
            }
        }
        return -1;
    }
};
