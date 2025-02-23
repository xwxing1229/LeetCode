# https://leetcode.cn/problems/range-frequency-queries/

class RangeFreqQuery:

    def __init__(self, arr):
        from collections import defaultdict
        self.idxs = defaultdict(list)
        for i, num in enumerate(arr):
            self.idxs[num].append(i)

    def query(self, left: int, right: int, value: int) -> int:
        idxs, n = self.idxs[value], len(self.idxs[value])
        i, j, idx1 = 0, n-1, n
        while i <= j:
            mid = i + (j - i) // 2
            if idxs[mid] < left:
                i = mid + 1
            else:
                j = mid - 1
                idx1 = mid
        
        i, j, idx2 = 0, n-1, -1
        while i <= j:
            mid = i + (j - i) // 2
            if idxs[mid] > right:
                j = mid - 1
            else:
                i = mid + 1
                idx2 = mid
        res = idx2 - idx1 + 1
        return res if res > 0 else 0


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)