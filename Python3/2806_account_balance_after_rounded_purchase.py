# https://leetcode.cn/problems/account-balance-after-rounded-purchase/

class Solution:
    def accountBalanceAfterPurchase(self, purchaseAmount: int) -> int:
        rem = purchaseAmount % 10
        rounded = purchaseAmount - rem
        if rem >= 5:
            rounded += 10
        return 100 - rounded