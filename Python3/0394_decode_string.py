# https://leetcode.cn/problems/decode-string/

class Solution:
    def decodeString(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """

        stack_nums = []
        num = 0
        stack_encodes = []
        encode = ""

        for i in range(len(s)):
            ch = s[i]
            if ch == "[":
                stack_nums.append([num, len(stack_encodes)])
                num = 0
            elif ch == "]":
                num, idx = stack_nums.pop()
                tmp = ""
                n = len(stack_encodes)
                for j in range(idx, n):
                    tmp = stack_encodes[-1] + tmp
                    stack_encodes.pop()
                tmp = tmp + encode

                stack_encodes.append(tmp * num)

                num = 0
                encode = ""

            elif (ch >= "0") and (ch <= "9"):
                num = num * 10 + int(ch)
                if (i > 0) and (s[i-1] >= 'a') and (s[i-1] <= 'z'):
                    stack_encodes.append(encode)
                    encode = ""
            else:
                encode = encode + ch

        res = ""
        for en in stack_encodes:
            res = res + en
        res = res + encode
        return res
