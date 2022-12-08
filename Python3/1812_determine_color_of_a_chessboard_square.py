# https://leetcode.cn/problems/determine-color-of-a-chessboard-square/

class Solution:
    def squareIsWhite(self, coordinates):
        """
        Inputs:
            coordinates: str
        Outputs:
            res: bool
        """
        if (ord(coordinates[0]) - ord("a") + int(coordinates[1])) % 2 == 0:
            return True
        else:
            return False