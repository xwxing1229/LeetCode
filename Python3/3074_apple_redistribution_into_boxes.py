# https://leetcode.cn/problems/apple-redistribution-into-boxes/

class Solution:
    def minimumBoxes(self, apple: list[int], capacity: list[int]) -> int:
        res = 0
        remain = sum(apple)
        capacity.sort(reverse=True)
        for cap in capacity:
            remain -= cap
            res += 1
            if remain <= 0:
                break
        return res