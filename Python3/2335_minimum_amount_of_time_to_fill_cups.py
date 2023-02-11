# https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/

class Solution:
    def fillCups(self, amount):
        """
        Inputs:
            amount: list[int]
        Outputs:
            res: int
        """

        # res = 0
        # while max(amount) > 0:
        #     amount.sort()
        #     amount[1] = max(0, amount[1] - 1)
        #     amount[2] = amount[2] - 1

        #     res += 1
        # return res

        # A better way.
        amount.sort()
        if amount[0] + amount[1] <= amount[2]:
            return amount[2]
        else:
            return (sum(amount) + 1) // 2