# https://leetcode.cn/problems/count-number-of-texts/

class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        n, MOD = len(pressedKeys), int(1e9)+7
        dp = [1 for _ in range(n+1)]
        cnt = 1
        for i in range(2, n+1):
            dp[i] = dp[i-1]
            cur = pressedKeys[i-1]
            if cur != pressedKeys[i-2]:
                cnt = 1
                continue

            cnt += 1
            cnt_max = 3 if (cur != "7" and cur != "9") else 4
            for k in range(2, min(cnt, cnt_max)+1):
                dp[i] = (dp[i] + dp[i-k]) % MOD
        return dp[-1]