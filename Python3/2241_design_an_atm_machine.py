# https://leetcode.cn/problems/design-an-atm-machine/

class ATM:

    def __init__(self):
        self.valids = [20, 50, 100, 200, 500]
        self.cnts = [0 for _ in range(5)]

    def deposit(self, banknotesCount: List[int]) -> None:
        for i, cnt in enumerate(banknotesCount):
            self.cnts[i] += cnt

    def withdraw(self, amount: int) -> List[int]:
        res = [0 for _ in range(5)]
        for i in range(4, -1, -1):
            k = min(self.cnts[i], amount//self.valids[i])
            amount -= k * self.valids[i]
            res[i] = k
        
        if amount != 0:
            return [-1]
        
        for i, cnt in enumerate(res):
            self.cnts[i] -= cnt
        
        return res


# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)