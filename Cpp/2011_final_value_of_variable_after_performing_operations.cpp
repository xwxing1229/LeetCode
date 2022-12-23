// https://leetcode.cn/problems/final-value-of-variable-after-performing-operations/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (string &s: operations) {
            if (s[1] == '+') res += 1;
            else res -= 1;
        }
        return res;
    }
};
