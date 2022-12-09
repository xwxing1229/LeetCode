# https://leetcode.cn/problems/check-if-number-is-a-sum-of-powers-of-three/

class Solution:
    def checkPowersOfThree(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: bool
        """

        # Check if there is a 2 in the number converted with base 3.
        while (n > 0):
            if (n % 3 == 2):
                return False
            n //= 3
        return True

        # Dfs is not necessary.
        # power_of_3 = 1
        # self.powers = [1]
        # while power_of_3 <= n // 3:
        #     power_of_3 *= 3
        #     self.powers.append(power_of_3)
        # self.powers.reverse()

        # self.res = False
        # for i, v in enumerate(self.powers):
        #     self.dfs(n, i, v)
        #     if self.res:
        #         return self.res
        # return self.res

    # def dfs(self, n, cur_idx, cur_sum):
    #     if cur_sum == n:
    #         self.res = True
    #         return
    #     for i in range(cur_idx+1, len(self.powers)):
    #         self.dfs(n, i, cur_sum+self.powers[i])