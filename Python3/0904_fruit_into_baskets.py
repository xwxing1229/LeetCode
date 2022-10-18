# https://leetcode.cn/problems/fruit-into-baskets/

class Solution:
    def totalFruit(self, fruits):
        """
        Inputs:
            fruits: list[int]
        Outputs:
            res: int
        """
        res = 1
        # dp: maximum number of fruits one can pick that end with current fruit
        # dp_pre: maximum number of fruits one can pick that end with last fruit
        dp, dp_pre = 1, 1
        type1, type2 = fruits[0], fruits[0]
        start = [0 for i in range(len(fruits))]
        for i in range(1, len(fruits)):
            fruit, fruit_pre = fruits[i], fruits[i-1]
            if fruit == type1 or fruit == type2:
                dp = dp_pre + 1
                if fruit != fruit_pre:
                    start[fruit] = i
            else:
                dp = i - start[fruit_pre] + 1
                start[fruit] = i
                type1 = fruit_pre
                type2 = fruit

            if dp > res:
                res = dp

            dp_pre = dp

        return res

