// https://leetcode.cn/problems/find-champion-i/
        
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int res = -1, n = grid.size();
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int val: grid[i]) {
                s += val;
            }
            if (s == n-1) {
                res = i;
                break;
            }
        }
        return res;
    }
};
