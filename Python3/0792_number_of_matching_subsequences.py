# https://leetcode.cn/problems/number-of-matching-subsequences/

class Solution:
    def numMatchingSubseq(self, s, words):
        """
        Inputs:
            s: str
            words: list[str]
        Outputs:
            res: int
        """
        idxs = defaultdict(list)
        for i, ch in enumerate(s):
            idxs[ch].append(i)

        res = len(words)
        for word in words:
            cur = -1
            for ch in word:
                # Find a minimum value in idxs_ch that is greater than cur.
                idxs_ch = idxs[ch]
                left, right = 0, len(idxs_ch)-1
                while left <= right:
                    mid = left + (right - left) // 2
                    if idxs_ch[mid] > cur:
                        right = mid - 1
                    else:
                        left = mid + 1
                if left >= len(idxs_ch):
                    res -= 1
                    break

                cur = idxs_ch[left]

        return res
