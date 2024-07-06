# https://leetcode.cn/problems/maximum-prime-difference/

class Solution:
    def maximumPrimeDifference(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        primes = set()
        for num in range(2, 100):
            is_prime = True
            for i in range(2, int(sqrt(num))+1):
                if num % i == 0:
                    is_prime = False
                    break
            if is_prime:
                primes.add(num)
        
        for i in range(len(nums)):
            if nums[i] in primes:
                for j in range(len(nums)-1, -1, -1):
                    if nums[j] in primes:
                        return j - i
        return -1