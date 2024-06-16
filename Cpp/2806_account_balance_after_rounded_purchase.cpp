// https://leetcode.cn/problems/account-balance-after-rounded-purchase/
        
class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int rem = purchaseAmount % 10;
        int rounded = purchaseAmount - rem;
        if (rem >= 5) rounded += 10;
        return 100 - rounded;
    }
};
