# https://leetcode.cn/problems/avoid-flood-in-the-city/

class Solution:
    def avoidFlood(self, rains):
        """
        Inputs:
            rains: list[int]
        Outputs:
            res: list[int]
        """
        res = [1 for _ in range(len(rains))]
        drydays = []
        fulllakes = dict()
        for i, lake in enumerate(rains):
            if lake == 0:
                drydays.append(i)
            else:
                res[i] = -1
                if fulllakes.get(lake, -1) >= 0:
                    k = -1
                    left, right = 0, len(drydays)-1
                    while left <= right:
                        mid = (left + right) // 2
                        if drydays[mid] > fulllakes[lake]:
                            k = mid
                            right = mid - 1
                        else:
                            left = mid + 1
                    if k < 0:
                        return []
                    res[drydays[k]] = lake
                    drydays.pop(k)
                fulllakes[lake] = i
        return res