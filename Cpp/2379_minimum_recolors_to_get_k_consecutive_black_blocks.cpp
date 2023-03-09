// https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // Sliding window.
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'B') {
                cnt += 1;
            }
        }
        int res = k - cnt;
        for (int i = k; i < blocks.size(); ++i) {
            char cur = blocks[i], drop = blocks[i-k];
            if (cur == 'B' && drop == 'W') {
                cnt += 1;
                res = min(res, k - cnt);
            }
            else if (cur == 'W' && drop == 'B') {
                cnt -= 1;
            }
        }
        return res;
    }
};
