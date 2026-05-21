# https://leetcode.cn/problems/find-the-length-of-the-longest-common-prefix/

class Solution:
    def longestCommonPrefix(self, arr1: list[int], arr2: list[int]) -> int:
        s = set()
        for i in range(len(arr1)):
            num = arr1[i]
            while num:
                s.add(num)
                num //= 10
        
        res = 0
        for i in range(len(arr2)):
            num = arr2[i]
            while num and num not in s:
                num //= 10
            res = max(res, num)
        return len(str(res)) if res else 0