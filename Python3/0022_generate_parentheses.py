# https://leetcode.cn/problems/generate-parentheses/

class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        st = [set() for _ in range(n+1)]
        st[1].add("()")
        for k in range(2, n+1):
            for i in range(1, k//2+1):
                j = k - i
                for s1 in st[i]:
                    for s2 in st[j]:
                        st[k].add(s1 + s2)
                        st[k].add(s2 + s1)
            for s in st[k-1]:
                st[k].add("(" + s + ")")
        return list(st[-1])