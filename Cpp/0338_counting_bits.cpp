// https://leetcode.cn/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        int k = 0, pow2 = 1;
        for (int i = 1; i <= n; ++i) {
            res[i] = res[k] + 1;
            k = k + 1;
            if (k == pow2) {
                k = 0;
                pow2 = pow2 * 2;
            }
        }
        return res;
    }
};
