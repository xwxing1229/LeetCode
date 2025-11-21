# https://leetcode.cn/problems/unique-length-3-palindromic-subsequences/

class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        ord_a = ord("a")
        position = [[] for _ in range(26)]
        for i, ch in enumerate(s):
            position[ord(ch) - ord_a].append(i)
        
        res = 0
        for i, pos_i in enumerate(position):
            if len(pos_i) < 2:
                continue
            start, stop = pos_i[0], pos_i[-1]
            for j, pos_j in enumerate(position):
                # Check whether there exists a valid index for the middle char.
                n = len(pos_j)
                if i == j:
                    res += (n > 2)
                    continue

                valid_min, valid_max = n, -1

                left, right = 0, n-1
                while left <= right:
                    mid = (left + right) // 2
                    if pos_j[mid] >= start:
                        right = mid - 1
                        valid_min = mid
                    else:
                        left = mid + 1

                left, right = 0, n-1
                while left <= right:
                    mid = (left + right) // 2
                    if pos_j[mid] <= stop:
                        left = mid + 1
                        valid_max = mid
                    else:
                        right = mid - 1

                res += (valid_min <= valid_max)

        return res