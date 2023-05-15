# https://leetcode.cn/problems/distant-barcodes/

class Solution:
    def rearrangeBarcodes(self, barcodes):
        """
        Inputs:
            barcodes: List[int]
        Outputs:
            res: list[int]
        """
        cnt = defaultdict(int)
        for code in barcodes:
            cnt[code] += 1
        barcodes.sort(key=lambda x: (-cnt[x], x))
        left, n = 0, len(barcodes)
        res = [0 for _ in range(n)]
        for i in range(0, n, 2):
            res[i] = barcodes[left]
            left += 1
        for i in range(1, n, 2):
            res[i] = barcodes[left]
            left += 1
        return res
