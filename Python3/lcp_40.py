# https://leetcode.cn/problems/uOAnQW/

class Solution:
    def maximumScore(self, cards, cnt):
        """
        Inputs:
            cards: list[int]
            cnt: int
        Outputs:
            res: int
        """
        res = 0

        cards.sort(reverse=True)
        odd_idx, even_idx = -1, -1
        for i, card in enumerate(cards):
            res += card
            cnt -= 1
            if card % 2:
                odd_idx = i
            else:
                even_idx = i
            if cnt == 0:
                break
        if res % 2 == 0:
            return res
        
        # Remove the minimum odd number and add the maximum in the remaining even numbers.
        tmp1 = 0
        if odd_idx >= 0:
            for i in range(even_idx+1, len(cards)):
                if cards[i] % 2 == 0:
                    tmp1 = res - cards[odd_idx] + cards[i]
                    break
        # Remove the minimum even number and add the maximum in the remaining odd numbers.
        tmp2 = 0
        if even_idx >= 0:
            for i in range(odd_idx+1, len(cards)):
                if cards[i] % 2:
                    tmp2 = res - cards[even_idx] + cards[i]
                    break
        return max(tmp1, tmp2)