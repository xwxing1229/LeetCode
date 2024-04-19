# https://leetcode.cn/problems/find-original-array-from-doubled-array/

class Solution:
    def findOriginalArray(self, changed):
        """
        Inputs:
            changed: list[int]
        Outputs:
            res: list[int]
        """
        res = []
        changed.sort()
        cnt = defaultdict(int)
        for num in changed:
            cnt[num] += 1
        for num in changed:
            if cnt[num] <= 0:
                continue
            if cnt[2*num] > 0:
                cnt[num] -= 1
                cnt[2*num] -= 1
                res.append(num)
            else:
                return []
            
        for k, v in cnt.items():
            if v != 0:
                return []
        return res