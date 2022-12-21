// https://leetcode.cn/problems/maximum-score-from-removing-stones/

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int s = a + b + c;
        int max_ = max({a, b, c});
        int res = 0;
        if (s <= max_ + max_) {
            res = s - max_;
        }
        else {
            res = (s - max_ - max_) / 2 + max_;
        }
        return res;
    }
};
