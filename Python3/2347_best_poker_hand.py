# https://leetcode.cn/problems/best-poker-hand/

class Solution:
    def bestHand(self, ranks, suits):
        """
        Inputs:
            ranks: list[int]
            suits: list[str]
        Outputs:
             res: str
        """
        cnt_suits = Counter(suits)
        if cnt_suits.most_common(1)[0][1] == 5:
            return "Flush"
        cnt_ranks = Counter(ranks)
        if cnt_ranks.most_common(1)[0][1] >= 3:
            return "Three of a Kind"
        elif cnt_ranks.most_common(1)[0][1] == 2:
            return "Pair"
        else:
            return "High Card"