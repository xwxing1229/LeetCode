# https://leetcode.cn/problems/merge-similar-items/

class Solution:
    def mergeSimilarItems(self, items1, items2):
        """
        Inputs:
            items1, items2: list[list[int]]
        Outputs:
            res: list[list[int]]
        """
        items1.sort()
        items2.sort()
        res = []
        i, j = 0, 0
        while i < len(items1) and j < len(items2):
            value, weight = 0, 0
            if items1[i][0] < items2[j][0]:
                value, weight = items1[i][0], items1[i][1]
                i += 1
            else:
                value, weight = items2[j][0], items2[j][1]
                j += 1
                if items1[i][0] == value:
                    weight += items1[i][1]
                    i += 1
            if len(res) == 0 or res[-1][0] < value:
                res.append([value, weight])
            else:
                res[-1][1] += weight
        if i == len(items1):
            while j < len(items2):
                if res[-1][0] == items2[j][0]:
                    res[-1][1] += items2[j][1]
                else:
                    res.append(items2[j])
                j += 1
        else:
            while i < len(items1):
                if res[-1][0] == items1[i][0]:
                    res[-1][1] += items1[i][1]
                else:
                    res.append(items1[i])
                i += 1
        return res