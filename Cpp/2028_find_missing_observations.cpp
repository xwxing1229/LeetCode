// https://leetcode.cn/problems/find-missing-observations/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), sm = 0, s = mean * (m+n);
        for(int r: rolls) sm += r;
        int sn = s - sm;
        if (sn < n || sn > 6*n) return vector<int>();

        vector<int> res(n, 1);
        sn -= n;
        for (int i = 0; i < n; ++i) {
            int add = min(5, sn);
            res[i] += add;
            sn -= add;
            if (sn == 0) break;
        }
        return res;
    }
};
