# https://leetcode.cn/problems/letter-case-permutation/

class Solution:
    def letterCasePermutation(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: list[str]
        """
        q = collections.deque()
        q.append("")
        for ch in s:
            n = len(q)
            for i in range(n):
                pre = q.popleft()
                tmp1 = pre + ch
                q.append(tmp1)
                if not ch.isdigit():
                    tmp2 = pre + ch.swapcase()
                    q.append(tmp2)

        res = list(q)
        return res
