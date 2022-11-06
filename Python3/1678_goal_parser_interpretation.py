# https://leetcode.cn/problems/goal-parser-interpretation/

class Solution:
    def interpret(self, command):
        """
        Inputs:
            command: str
        Outputs:
            res: str
        """
        res = ""
        i = 0
        while i < len(command):
            if command[i] == "G":
                res += "G"
                i += 1
            else:
                if command[i+1] == ")":
                    res += "o"
                    i += 2
                else:
                    res += "al"
                    i += 4
        return res
