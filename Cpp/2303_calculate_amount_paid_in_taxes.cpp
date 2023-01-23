// https://leetcode.cn/problems/calculate-amount-paid-in-taxes/

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int res = 0, lower = 0;
        for (auto br: brackets) {
            int upper = br[0];
            res += (min(income, upper) - lower) * br[1];
            if (upper >= income) {
                break;
            }
            lower = upper;
        }
        return (double) res / 100.;
    }
};