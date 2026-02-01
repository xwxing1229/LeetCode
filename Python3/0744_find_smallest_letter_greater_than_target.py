# https://leetcode.cn/problems/find-smallest-letter-greater-than-target/

class Solution:
    def nextGreatestLetter(self, letters: list[str], target: str) -> str:
        res = letters[0]
        for ch in letters:
            if ch > target:
                return ch
        return res
