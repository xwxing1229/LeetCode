# https://leetcode.cn/problems/find-the-winning-player-in-coin-game/

class Solution:
    def losingPlayer(self, x: int, y: int) -> str:
        cnt = min(x, y//4)
        res = "Alice" if cnt % 2 == 1 else "Bob"
        return res