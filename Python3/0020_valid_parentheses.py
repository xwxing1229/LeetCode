# https://leetcode.cn/problems/valid-parentheses/

class Solution:
    def isValid(self, s: str) -> bool:
        m = {")": "(", "]": "[", "}": "{"}
        stack = []
        for ch in s:
            if ch not in m:
                stack.append(ch)
            elif not stack or stack.pop() != m[ch]:
                return False
        return len(stack) == 0