// https://leetcode.cn/problems/maximum-split-of-positive-even-integers/

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum % 2 == 1) {
            return res;
        }
        long long cur = 2;
        while (finalSum > 0) {
            res.push_back(cur);
            finalSum -= cur;
            cur += 2;
            if (finalSum < cur) {
                res.back() += finalSum;
                finalSum = 0;
            }
        }
        return res;
    }
};
