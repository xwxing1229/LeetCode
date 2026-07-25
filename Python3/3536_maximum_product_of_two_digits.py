# https://leetcode.cn/problems/maximum-product-of-two-digits/

class Solution:
    def maxProduct(self, n: int) -> int:
        mx1, mx2 = 0, 0
        while n > 0:
            num = n % 10
            n //= 10
            if num >= mx1:
                mx2 = mx1
                mx1 = num
            elif num > mx2:
                mx2 = num
        return mx1 * mx2