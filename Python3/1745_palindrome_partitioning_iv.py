# https://leetcode.cn/problems/palindrome-partitioning-iv/

class Solution:
    def checkPartitioning(self, s: str) -> bool:
        def update_palindrome(left, right):
            while left >= 0 and right < n and s[left] == s[right]:
                palindrome[left][right] = True
                left -= 1
                right += 1

        n = len(s)
        palindrome = [[False for _ in range(n)] for _ in range(n)]
        for i in range(n):
            update_palindrome(i, i)
            update_palindrome(i, i+1)
        
        for i in range(1, n):
            for j in range(i+1, n):
                if palindrome[0][i-1] and palindrome[i][j-1] and palindrome[j][n-1]:
                    return True
        return False