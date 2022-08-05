// https://leetcode.cn/problems/super-ugly-number/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Similar to #0264.
        vector<int> uglys(n, 1); // save ugly numbers in order
        int k = primes.size();
        vector<long> ids(k, 0), nums(k, 0);
        for (int i = 1; i < n; ++i) {
            long num_min = (long)uglys[ids[0]] * primes[0];
            for (int j = 0; j < k; ++j) {
                nums[j] = (long)uglys[ids[j]] * primes[j];
                num_min = min(num_min, nums[j]);
            }
            uglys[i] = num_min;
            for (int j = 0; j < k; ++j) {
                if (nums[j] == num_min) {
                    ids[j] = ids[j] + 1;
                }
            }
        }
        return uglys[n-1];
    }
};
