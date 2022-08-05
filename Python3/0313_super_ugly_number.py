# https://leetcode.cn/problems/super-ugly-number/

class Solution:
    def nthSuperUglyNumber(self, n, primes):
        """
        Inputs:
            n: int
            primes: list[int]
        Outputs:
            res: int
        """
        
        # Similar to #0264.
        uglys = [1 for _ in range(n)]
        k = len(primes)
        ids = [0 for _ in range(k)]
        nums = [0 for _ in range(k)]
        for i in range(1, n):
            num_min = uglys[ids[0]] * primes[0]
            for j in range(k):
                nums[j] = uglys[ids[j]] * primes[j]
                num_min = min(num_min, nums[j])

            uglys[i] = num_min

            for j in range(k):
                if nums[j] == num_min:
                    ids[j] = ids[j] + 1
        return uglys[n-1]