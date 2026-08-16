# https://leetcode.cn/problems/stone-game-ix/

class Solution:
    def stoneGameIX(self, stones: list[int]) -> bool:
        n = len(stones)
        count = [0] * 3
        for x in stones:
            count[x % 3] += 1

        def check(cnt: list[int]) -> bool:
            if cnt[1] < 1:
                return False
            cnt[1] -= 1
            rounds = 1 + 2 * min(cnt[1], cnt[2]) \
                + (cnt[1] > cnt[2]) + cnt[0]
            return rounds < n and rounds % 2 == 1

        return check([count[0], count[1], count[2]]) \
            or check([count[0], count[2], count[1]])