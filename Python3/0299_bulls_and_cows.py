# https://leetcode.cn/problems/bulls-and-cows/

class Solution:
    def getHint(self, secret, guess):
        """
        Inputs:
            secret: str
            guess: str
        Outputs:
            res: str
        """
        cnt_secret = {}
        cnt_guess = {}
        bull = 0
        cow = 0
        for i in range(len(secret)):
            ch_secret = secret[i]
            ch_guess = guess[i]
            if ch_secret == ch_guess:
                bull = bull + 1
            else:
                cnt_secret[ch_secret] = cnt_secret.get(ch_secret,0) + 1
                cnt_guess[ch_guess] = cnt_guess.get(ch_guess,0) + 1
        
        for ch in cnt_guess:
            if ch in cnt_secret:
                cow = cow + min(cnt_secret[ch], cnt_guess[ch])
        return str(bull) + "A" + str(cow) + "B"