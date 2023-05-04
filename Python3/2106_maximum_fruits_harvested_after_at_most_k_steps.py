# https://leetcode.cn/problems/maximum-fruits-harvested-after-at-most-k-steps/

class Solution:
    def maxTotalFruits(self, fruits, startPos, k):
        """
        Inputs:
            fruits: list[list[int]]
            startPos, k: int
        Outputs:
            res: int
        """
        self.leftpos, self.rightpos = fruits[0][0], fruits[-1][0]
        n = self.rightpos - self.leftpos + 1
        self.cumsum = [0 for i in range(n+1)]

        idx = 0
        for i in range(n):
            if i + fruits[0][0] == fruits[idx][0]:
                self.cumsum[i+1] = self.cumsum[i] + fruits[idx][1]
                idx += 1
            else:
                self.cumsum[i+1] = self.cumsum[i]

        startCnt = 0
        l, r = 0, len(fruits)-1
        while l <= r:
            m = (l + r) // 2
            if fruits[m][0] == startPos:
                startCnt = fruits[m][1]
                break
            elif fruits[m][0] < startPos:
                l = m + 1
            else:
                r = m - 1
        res = max(self.firstLeftThenRight(startPos, k, startCnt),
                  self.firstRightThenLeft(startPos, k, startCnt))

        return res

    def firstLeftThenRight(self, startPos, k, startCnt):
        res = startCnt
        for i in range(1, k+1):
            left = startPos - i - self.leftpos
            left = max(left, 0)
            right = max(startPos, startPos-i+k-i) - self.leftpos
            right = min(right, self.rightpos - self.leftpos)
            if left >= len(self.cumsum) or right < 0:
                continue
            res = max(res, self.cumsum[right+1] - self.cumsum[left])
        return res

    def firstRightThenLeft(self, startPos, k, startCnt):
        res = startCnt
        for i in range(1, k+1):
            right = startPos + i - self.leftpos
            right = min(right, self.rightpos - self.leftpos)
            left = min(startPos, startPos+i-k+i) - self.leftpos
            left = max(left, 0)
            if left >= len(self.cumsum) or right < 0:
                continue
            res = max(res, self.cumsum[right+1] - self.cumsum[left])
        return res

sol = Solution()
# fruits = [[2,8],[6,3],[8,6]]
# startPos = 5
# k = 4
# fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]]
# startPos = 5
# k = 4
# fruits = [[0,3],[6,4],[8,5]]
# startPos = 3
# k = 2
fruits = [[200000,10000]]
startPos = 0
k = 200000
print(sol.maxTotalFruits(fruits, startPos, k))