# https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/

class Solution:
    def successfulPairs(self, spells, potions, success):
        """
        Inputs:
            spells, potions: list[int]
            success: int
        Outputs:
            res: list[int]
        """
        m, n = len(spells), len(potions)
        res = [0 for _ in range(m)]
        potions.sort()
        for i, spell in enumerate(spells):
            left, right = 0, n-1
            start = n
            while left <= right:
                mid = (left + right) // 2
                product = spell * potions[mid]
                if product >= success:
                    right = mid - 1
                    start = mid
                else:
                    left = mid + 1
            res[i] = n - start
        return res