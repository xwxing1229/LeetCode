// https://leetcode.cn/problems/reach-a-number/

class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) {
            target = -target;
        }
        // Find the smallest n s.t. 1 + 2 + ... + n >= target.
        int n = ceil((sqrt((long)8 * target + 1) - 1) / 2);
        int cur = (n + 1) * n / 2;
        int res;
        // cur == target, or (cur - target) % 2 == 0
        if ((cur - target) % 2 == 0) {
            res = n;
        }
        else {
            res = n + 1 + n%2;
        }
        return res;
    }
};

