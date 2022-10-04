# https://leetcode.cn/problems/utf-8-validation/

class Solution:
    def validUtf8(self, data):
        """
        Inputs:
            data: list[int]
        Outputs:
            res: bool
        """

        i = 0
        n = len(data)
        while i < n:
            num = data[i]
            if (num & 128) == 0:
                i = i + 1
                continue

            j = 0
            while j < 4:
                if (num & 128) != 0:
                    j = j + 1
                    num = num << 1
                else:
                    break
            if (j == 1) or ((num & 128) != 0):
                return False

            for k in range(1, j):
                if i + k >= n:
                    return False
                num = data[i+k]
                if (num & 128) == 0:
                    return False
                num = num << 1
                if (num & 128) != 0:
                    return False

            i = i + j
        return True
