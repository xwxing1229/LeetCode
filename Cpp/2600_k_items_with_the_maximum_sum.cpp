// https://leetcode.cn/problems/k-items-with-the-maximum-sum/

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int tmp = min(numOnes, k);
        int res = tmp;
        k -= tmp;
        if (k > 0) {
            tmp = min(numZeros, k);
            k -= tmp;
        }
        if (k > 0) {
            tmp = min(numNegOnes, k);
            res -= tmp;
        }
        return res;
    }
};