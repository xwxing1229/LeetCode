# https://leetcode.cn/problems/break-a-palindrome/

class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        n = len(palindrome)
        if n == 1:
            return ""
        
        res = list(palindrome)
        idx = -1
        for i in range((n+1)//2):
            if palindrome[i] != "a":
                idx = i
                break
        if (idx == n // 2 and n % 2 == 1) or idx < 0:
            res[-1] = "b"
        else:
            res[idx] = "a"
        return "".join(res)