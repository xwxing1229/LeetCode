# https://leetcode.cn/problems/string-compression/

class Solution:
    def compress(self, chars):
        """
        Inputs:
            chars: list[str]
        Outputs:
            res: int
        """

        res = 0
        start, pre = 0, -1
        for i in range(len(chars)):
            if (i == len(chars)-1) or (chars[i] != chars[i+1]):
                chars[start] = chars[i]

                cnt = i - pre
                digits = 0
                if cnt > 1:
                    while cnt:
                        digits += 1
                        chars[start + digits] = str(cnt % 10)
                        cnt = cnt // 10
                    # Reverse.
                    for j in range(1, digits//2+1):
                        tmp = chars[start + j]
                        chars[start + j] = chars[start + 1 + digits - j]
                        chars[start + 1 + digits - j] = tmp

                res += (1 + digits)
                start += (1 + digits)
                pre = i

        return res
