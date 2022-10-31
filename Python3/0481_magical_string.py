# https://leetcode.cn/problems/magical-string/

class Solution:
    def magicalString(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        if n <= 3:
            return 1

        magi = [1 for i in range(n)]
        magi[1] = 2
        res = 1
        idx, cnt = 1, 1
        for i in range(2, n):
            pre = magi[i-1]
            if magi[idx] == 1:
                cur = 3 - pre
                idx += 1
                cnt = 0
            else:
                if cnt == 0:
                    cur = 3 - pre
                    cnt = 1
                else:
                    cur = pre
                    idx += 1
                    cnt = 0
            magi[i] = cur

            if cur == 1:
                res += 1
        return res