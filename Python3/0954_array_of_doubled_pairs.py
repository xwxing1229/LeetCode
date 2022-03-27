# https://leetcode-cn.com/problems/array-of-doubled-pairs/
class Solution:
    def canReorderDoubled(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: bool
        """

        count = {}
        for num in arr:
            count[num] = count.gey(num,0) + 1
        count = dict(sorted(count.items()))
        for i in count:
            while count[i] > 0:
                count[i] = count[i] - 1
                if i < 0 and i/2*2 == i and count.get(i/2,0) > 0:
                    count[i/2] = count[i/2] - 1
                elif i == 0:
                    count[i] = count[i] - 1
                elif i > 0 and count.get(2*i,0) > 0:
                    count[2*i] = count[2*i] - 1
                else:
                    return False
        return True