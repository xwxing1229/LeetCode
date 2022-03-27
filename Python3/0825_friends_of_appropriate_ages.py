# https://leetcode-cn.com/problems/friends-of-appropriate-ages/
class Solution:
    def numFriendRequests(self, ages):
        """
        Inputs:
            ages: list[int]
        Outputs:
            res: int
        """

        ages.sort(resverse=True)
        n = len(ages)
        res = 0

        # ages[i]: A, ages[j]: B
        j = 1
        for i in range(n-1):
            while j < n and ages[j] > 0.5 * ages[i] + 7:
                j = j + 1
            if j > i:
                res = res + j - i - 1

        # ages[i]: B, ages[j]: A
        for i in range(n-1, 0, -1):
            while j > -1 and ages[j] == ages[i] and ages[j] > 14:
                j = j - 1

            if j < i:
                res = res + i - j - 1
            else:
                j = j - 1

        return res