# https://leetcode.cn/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution:
    def reverseParentheses(self, s: str) -> str:
        prev = []
        slist = list(s)
        for i, ch in enumerate(s):
            if ch == "(":
                prev.append(i)
            elif ch == ")":
                begin, end = prev[-1] + 1, i - 1
                tmp = begin + end
                for left in range(begin, (tmp+1)//2):
                    right = tmp - left
                    slist[left], slist[right] = slist[right], slist[left]
                prev.pop()
        res = ""
        for ch in slist:
            if ch != "(" and ch != ")":
                res += ch
        return res