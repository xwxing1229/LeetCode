// https://leetcode.cn/problems/number-of-common-factors/

class Solution {
public:
    int commonFactors(int a, int b) {
        unordered_set<int> factors_a;
        for (int i = 1; i <= (int)sqrt(a); ++i) {
            if (a % i == 0) {
                factors_a.insert(i);
                factors_a.insert(a / i);
            }
        }
        int res = 0;
        for (int i = 1; i <= (int)sqrt(b); ++i) {
            if (b % i != 0) continue;
            if (factors_a.find(i) != factors_a.end()) {
                res += 1;
            }
            int j = b / i;
            if (i != j && factors_a.find(j) != factors_a.end()) {
                res += 1;
            }
        }
        return res;
    }
};
