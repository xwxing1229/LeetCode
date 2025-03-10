# https://leetcode.cn/problems/maximum-total-beauty-of-the-gardens/

class Solution:
    def maximumBeauty(self, flowers, newFlowers, target, full, partial):
        """
        Inputs:
            flowers: list[int]
            newFlowers, target, full, partial: int
        Outputs;
            res: int
        """
        n = len(flowers)
        need = sum([target - min(target, f) for f in flowers])
        if need == 0:
            return full * n
        elif need <= newFlowers:
            tmp1 = full * n
            tmp2 = full * (n - 1) + partial * (target - 1)
            return max(tmp1, tmp2)
        
        # Try to make flowers[i+1: n] complete for i = 0, ..., n-1.
        res = 0
        flowers.sort()
        j, cumsum = 0, 0
        for i in range(n):
            if target > flowers[i]:
                need -= target - flowers[i]
            remain = newFlowers - need
            if remain < 0:
                continue

            while j <= i and flowers[j] * j <= cumsum + remain:
                cumsum += flowers[j]
                j += 1
            num = (cumsum + remain) // j
            tmp = full * (n - i - 1) + partial * num
            res = max(res, tmp)
        return res