// https://leetcode.cn/problems/minimum-number-of-operations-to-reinitialize-a-permutation/

class Solution {
public:
    int reinitializePermutation(int n) {
        int res = 0;
        int start = 1, cur = 1, half = n / 2;
        while (true) {
            if (cur < half) cur *= 2;
            else cur = cur * 2 + 1 - n;
            res += 1;
            if (start == cur) break;
        }
        return res;
    }
};
