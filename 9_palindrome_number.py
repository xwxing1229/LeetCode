# https://leetcode-cn.com/problems/palindrome-number/

class Solution:
    def isPalindrome(self, x:int) -> bool:
        if 0 <= x < 10:
            return True
        if (x < 0) or (x % 10 == 0):
            return False

        y = 0
        while True:
            y = y * 10 + x % 10
            x = x // 10
            if y == x:
                res = True
                break
            elif y < x:
                if y == (x // 10):
                    res = True
                    break
            else:
                res = False
                break
        return res