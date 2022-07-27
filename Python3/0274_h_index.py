# https://leetcode.cn/problems/h-index/

class Solution:
    def hIndex(self, citations):
        """
        Inputs:
            citations: list[int]
        Outputs:
            res: int
        """

        # # Time complexity: O(n*log(n)), space complexity: O(n*log(n)).
        # citations.sort()
        # n = len(citations)

        # res = 0
        # for i in range(n):
        #     if n-i <= citations[i]:
        #         res = n - i
        #         break
        # return res

        # Time complexity: O(n), space complexity: O(n).
        n = len(citations)
        counts = [0 for _ in range(n+1)]
        for cita in citations:
            if cita >= n:
                counts[n] = counts[n] + 1
            else:
                counts[cita] = counts[cita] + 1

        cnt = 0
        res = 0
        for i in range(n, -1, -1):
            cnt = cnt + counts[i]
            if cnt >= i:
                res = i
                break
        return res