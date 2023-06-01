# https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/

class Solution:
    def maximumTastiness(self, price, k):
        """
        Inputs:
            price: list[int]
            k: int
        Outputs:
            res: int
        """
        n = len(price)
        price.sort()
        left, right = 0, price[n-1] - price[0]
        res = 0
        while left <= right:
            mid = (left + right) // 2

            # Try to find k candies such that their minimum difference
            # is >= mid.
            pre = -inf;
            cnt = 0
            for p in price:
                if p - pre >= mid:
                    cnt += 1
                    pre = p

            if cnt >= k:
                res = mid
                left = mid + 1
            else:
                right = mid - 1

        return res