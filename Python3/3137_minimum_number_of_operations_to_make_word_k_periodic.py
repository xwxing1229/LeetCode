# https://leetcode.cn/problems/minimum-number-of-operations-to-make-word-k-periodic/

class Solution:
    def minimumOperationsToMakeKPeriodic(self, word: str, k: int) -> int:
        n = len(word)
        cnt = defaultdict(int)
        cnt_max = 0
        for i in range(0, n, k):
            cnt[word[i: i+k]] += 1
            cnt_max = max(cnt_max, cnt[word[i: i+k]])
        return n // k - cnt_max