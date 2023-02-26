# https://leetcode.cn/problems/maximum-score-words-formed-by-letters/

class Solution:
    def maxScoreWords(self, words, letters, score):
        """
        Inputs:
            words: list[str]
            letters: list[str]
            score: list[int]
        Outputs:
            res: int
        """
        self.words = words
        self.cnt = Counter(letters)
        self.score_words = []
        for word in words:
            s = 0
            for le in word:
                s += score[ord(le) - ord("a")]
            self.score_words.append(s)
        
        self.res = 0
        self.dfs(0, 0)
        return self.res

    def dfs(self, idx, score_cur):
        for i in range(idx, len(self.words)):
            word, valid = self.words[i], True
            cnt_words = Counter(word)
            for le in cnt_words:
                if cnt_words[le] > self.cnt[le]:
                    valid = False
                    break
            if valid:
                for le in cnt_words:
                    self.cnt[le] -= cnt_words[le]
                self.res = max(self.res, score_cur + self.score_words[i])
                self.dfs(i+1, score_cur + self.score_words[i])
                for le in cnt_words:
                    self.cnt[le] += cnt_words[le]