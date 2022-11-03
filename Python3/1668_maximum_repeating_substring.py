# https://leetcode.cn/problems/maximum-repeating-substring/

class Solution:
    def maxRepeating(self, sequence, word):
        """
        Inputs:
            sequence: str
            word: str
        Outputs:
            res: int
        """

        '''
        res = 0
        n_seq, n_word = len(sequence), len(word)
        for i in range(n_seq - n_word + 1):
            j, cnt = i, 0
            while (j <= n_seq - n_word) and (sequence[j: j+n_word] == word):
                j += n_word
                cnt += 1
            if cnt > res:
                res = cnt
        return res
        '''

        # When the size of sequence is large, the following DP-based method should
        # be used.
        # dp[i]: maximum number of repeatitions of word in sequence[0: i+len(word)].
        res = 0
        n_seq, n_word = len(sequence), len(word)
        dp = [0 for i in range(n_seq)]
        for i in range(n_seq - n_word + 1):
            if sequence[i: i+n_word] == word:
                dp[i] = 1
                if i >= n_word:
                    dp[i] += dp[i - n_word]

            if dp[i] > res:
                res = dp[i]

        return res