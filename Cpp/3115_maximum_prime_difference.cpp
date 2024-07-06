// https://leetcode.cn/problems/maximum-prime-difference/

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> primes(101, 0);
        for (int num = 2; num < 100; ++num) {
            bool is_prime = true;
            for (int i = 2; i <= int(sqrt(num)); ++i) {
                if (num % i == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) {
                primes[num] = 1;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (primes[nums[i]] == 1) {
                for (int j = nums.size()-1; j >= 0; --j) {
                    if (primes[nums[j]] == 1) {
                        return j - i;
                    }
                }
            }
        }
        return -1;
    }
};
