# https://leetcode.cn/problems/find-the-number-of-good-pairs-ii/

class Solution:
    def numberOfPairs(self, nums1, nums2, k):
        """
        Inputs:
            nums1, nums2: list[int]
            k: int
        Outputs:
            res: int
        """
        cnts = defaultdict(int)
        for i in range(len(nums1)):
            num = nums1[i]
            if num % k != 0:
                continue
            num //= k
            for val in range(1, int(sqrt(num))+1):
                if num % val == 0:
                    cnts[val] += 1
                    if val * val != num:
                        cnts[num // val] += 1
        res = 0
        for num in nums2:
            res += cnts[num]
        return res