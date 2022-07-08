// https://leetcode.cn/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n, 1);
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (primes[i] == 1) {
                res = res + 1;

                for (int k = i; k <= (n-1)/i; ++k) {
                    primes[k*i] = 0;
                }
            }
        }
        return res;
    }
};
