# https://leetcode.cn/problems/generate-parentheses/
class Solution:
    def generateParenthesis(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: list[str]
        """

        res = set()
        res.add("()")
        k = 1
        while k < n:
            res_k = set()
            while res:
                cand = res.pop()
                for i in range(len(cand)):
                    cand_i = cand[:i] + '(' + cand[i:]

                    for j in range(1, len(cand_i)+1):
                        cand_ij = cand_i[:j] + ')' + cand_i[j:]

                        if self.isValid(cand_ij):
                            res_k.add(cand_ij)

            res = res_k
            k = k + 1

        return list(res)


    def isValid(self, s):
        counter = 0
        for c in s:
            if c == '(':
                counter = counter + 1
            elif counter > 0:
                counter = counter - 1
            else:
                return False
        return True