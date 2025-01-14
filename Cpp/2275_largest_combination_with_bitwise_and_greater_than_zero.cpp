// https://leetcode.cn/problems/largest-combination-with-bitwise-and-greater-than-zero/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnts(24, 0);
        for (int i = 0; i < candidates.size(); ++i) {
            int num = candidates[i], k = 0;
            while (num > 0) {
                cnts[k] += (num & 1);
                num >>= 1;
                k += 1;
            }
        }
        int res = cnts[0];
        for (int c: cnts) {
            res = max(res, c);
        }
        return res;
    }
};
