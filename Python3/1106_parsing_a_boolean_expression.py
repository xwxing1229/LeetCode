# https://leetcode.cn/problems/parsing-a-boolean-expression/

class Solution:
    def parseBoolExpr(self, expression):
        """
        Inputs:
            expression: str
        Outputs:
            res: bool
        """
        stk = []
        for ch in expression:
            if ch == "," or ch == "(":
                continue
            elif ch == ")":
                cnt_t, cnt_f = 0, 0
                while stk:
                    cur = stk.pop()
                    if cur == "t":
                        cnt_t += 1
                    elif cur == "f":
                        cnt_f += 1
                    elif cur == "&":
                        if cnt_f > 0:
                            stk.append("f")
                        else:
                            stk.append("t")
                        break
                    elif cur == "|":
                        if cnt_t > 0:
                            stk.append("t")
                        else:
                            stk.append("f")
                        break
                    else:
                        if cnt_t > 0:
                            stk.append("f")
                        else:
                            stk.append("t")
                        break
            else:
                stk.append(ch)
        if stk[0] == "t":
            return True
        else:
            return False