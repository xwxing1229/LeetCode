// https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array/
        
class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        int half = target / 2, mod = 1e9+7;
        int res = 0;
        if (n <= half) {
            res = (((long long)1+n) * n / 2) % mod;
        }
        else {
            res = (((long long)1+half) * half / 2 +
                   ((long long)target+target+n-half-1) * (n-half) / 2 ) % mod;
        }
        return res;
    }
};
