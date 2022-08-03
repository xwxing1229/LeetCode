# https://leetcode.cn/problems/additive-number/

class Solution:
    def isAdditiveNumber(self, num):
        """
        Inputs:
            num: str
        Outputs:
            res: bool
        """
        self.res = False
        n = len(num)
        for idx2 in range(1, n//3*2+1):
            for idx3 in range(idx2+1, n):
                self.backtrack(num, 0, idx2, idx3, False)
                if self.res:
                    return self.res
        return self.res

    def backtrack(self, num, idx1, idx2, idx3, flag):
        n = len(num)
        if idx3 == n:
            if flag:
                self.res = True
            return

        num1 = num[idx1: idx2]
        num2 = num[idx2: idx3]
        len3 = max(idx2-idx1, idx3-idx2)
        for i in range(len3, len3+2):
            if idx3+i > n:
                break
            num3 = num[idx3: idx3+i]
            if self.isSum(num1, num2, num3):
                self.backtrack(num, idx2, idx3, idx3+i, True)

    def isSum(self, num1, num2, num3):
        # Check if num1 + num2 is equal to num3 where num1, num2 and num3 are
        # expressed using string.
        n1 = len(num1)
        n2 = len(num2)
        n3 = len(num3)
        if (n3 < n1) or (n3 < n2):
            return False
        if ((n1 > 1) and (num1[0] == '0')) or ((n2 > 1) and (num2[0] == '0')) or\
            ((n3 > 1) and (num3[0] == '0')):
            return False

        num1 = '0' * (n3-n1) + num1
        num2 = '0' * (n3-n2) + num2
        carry = 0
        for i in range(n3-1, -1, -1):
            tmp = int(num1[i]) + int(num2[i]) + carry
            if tmp % 10 != int(num3[i]):
                return False
            carry = tmp // 10
        return True