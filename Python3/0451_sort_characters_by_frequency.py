# https://leetcode-cn.com/problems/sort-characters-by-frequency/

class Solution:
    def frequencySort(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """

        count = {}
        for i in s:
            count[i] = count.get(i,0) + 1

        # Sort according to occurrence frequency.
        count_sort = sorted(count.items(), key=lambda x:-x[1])

        res = ''
        for i in count_sort:
            res = res + i[0] * i[1]

        return res