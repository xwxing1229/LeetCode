# https://leetcode.cn/problems/sort-integers-by-the-power-value/

class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        records = [0 for _ in range(hi+1)]
        for num in range(2, hi+1):
            cur, cnt = num, 0
            while cur >= num:
                if cur % 2 == 0:
                    cur //= 2
                else:
                    cur = 3 * cur + 1
                cnt += 1
            records[num] = records[cur] + cnt
        
        nums = [(records[num], num) for num in range(lo, hi+1)]
        nums.sort()
        return nums[k-1][1]