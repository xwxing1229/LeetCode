# https://leetcode.cn/problems/valid-palindrome-ii/

class Solution:
    def validPalindrome(self, s: str) -> bool:
        def dfs(left, right, cnt):
            if cnt >= 2:
                return False
            while left < right:
                if s[left] == s[right]:
                    left += 1
                    right -= 1
                else:
                    return dfs(left+1, right, cnt+1) or dfs(left, right-1, cnt+1)
            return True
        
        return dfs(0, len(s)-1, 0)