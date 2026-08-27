# https://leetcode.cn/problems/lexicographically-smallest-permutation-greater-than-target/

from collections import Counter

class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        count = Counter(s)
        for ch in target:
            count[ch] -= 1
        
        n = len(s)
        for i in range(n-1, -1, -1):
            # Try to replace target[i] with a larger char.
            ch = target[i]
            count[ch] += 1
            if any(cnt < 0 for cnt in count.values()):
                continue
            for j in range(ord(ch)+1, ord("z")+1):
                ch_new = chr(j)
                if count[ch_new] <= 0:
                    continue

                # Replace target[i] with ch_new.
                res = list(target[: i])
                res.append(ch_new)
                count[ch_new] -= 1
                for k in range(26):
                    x = chr(ord("a") + k)
                    res.extend(x * count[x])
                return "".join(res)
        return ""