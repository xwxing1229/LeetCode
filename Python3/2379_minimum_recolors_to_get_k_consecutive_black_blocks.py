# https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

class Solution:
    def minimumRecolors(self, blocks, k):
        """
        Inputs:
            blocks: str
            k: int
        Outputs:
            res: int
        """
        # Sliding window.
        cnt = 0
        for i in range(k):
            if blocks[i] == "B":
                cnt += 1
        res = k - cnt
        for i in range(k, len(blocks)):
            cur, drop = blocks[i], blocks[i-k]
            if cur == "B" and drop == "W":
                cnt += 1
                res = min(res, k - cnt)
            elif cur == "W" and drop == "B":
                cnt -= 1
        return res