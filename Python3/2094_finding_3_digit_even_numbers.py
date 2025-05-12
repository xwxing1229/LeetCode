# https://leetcode.cn/problems/finding-3-digit-even-numbers/

import heapq

class Solution:
    def findEvenNumbers(self, digits):
        """
        Inputs:
            digits: list[int]
        Outputs:
            res: list[int]
        """
        digits.sort()
        base = [[100,10,1], [10,100,1], [100,1,10], [1,100,10], [10,1,100], [1,10,100]]
        s = set()
        pq = []
        n = len(digits)
        for i in range(n):
            if i > 0 and digits[i] == digits[i-1]:
                continue
            for j in range(i+1, n):
                if j > i+1 and digits[j] == digits[j-1]:
                    continue
                for k in range(j+1, n):
                    if k > j+1 and digits[k] == digits[k-1]:
                        continue
                    for b in base:
                        num = digits[i] * b[0] + digits[j] * b[1] + digits[k] * b[2]
                        if num // 100 > 0 and num % 2 == 0 and num not in s:
                            s.add(num)
                            heapq.heappush(pq, num)
        res = []
        while pq:
            res.append(heapq.heappop(pq))
        return res