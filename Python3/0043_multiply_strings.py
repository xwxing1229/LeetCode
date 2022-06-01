# https://leetcode.cn/problems/multiply-strings/

class Solution:
    def multiply(self, num1, num2):
        """
        Inputs:
            num1: str
            num2: str
        Outputs:
            res: str
        """

        n1 = len(num1)
        n2 = len(num2)
        mul = [0 for _ in range(n1 + n2)]

        for j in range(n2-1, -1, -1):
            v2 = ord(num2[j]) - ord('0')
            carry_global = 0
            carry_local = 0
            for i in range(n1-1, -1, -1):
                v1 = ord(num1[i]) - ord('0')

                tmp_local = v1 * v2 + carry_local
                carry_local = tmp_local // 10
                left_local = tmp_local % 10

                tmp_global = mul[i+j+1] + left_local + carry_global
                carry_global = tmp_global // 10
                mul[i+j+1] = tmp_global % 10

            mul[i+j] = carry_local + carry_global

        mul_str = [str(i) for i in mul]
        for k in range(n1+n2):
            if mul[k] != 0:
                break
        res = "".join(mul_str[k:])
        return res

solu = Solution()
print(solu.multiply("0", "0"))