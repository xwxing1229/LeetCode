# https://leetcode.cn/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        record = set()
        for i in range(len(s)-k+1):
            record.add(s[i:i+k])
        return 2**k == len(record)