# https://leetcode.cn/problems/fizz-buzz/

class Solution:
    def fizzBuzz(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: list[str]
        """
        res = ["" for i in range(n)]
        for i in range(n):
            val = i + 1
            if val % 3 == 0:
                if val % 5 == 0:
                    res[i] = "FizzBuzz"
                else:
                    res[i] = "Fizz"
            elif val % 5 == 0:
                res[i] = "Buzz"
            else:
                res[i] = str(val)
        return res