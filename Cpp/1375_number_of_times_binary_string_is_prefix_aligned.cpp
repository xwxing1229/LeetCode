// https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned/

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int res = 0, max_ = 0;
        for (int i = 0; i < flips.size(); ++i) {
            if (max_ < flips[i]) {
                max_ = flips[i];
            }
            if (i + 1 == max_) {
                res += 1;
            }
        }
        return res;
    }
};