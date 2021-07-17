# https://leetcode-cn.com/problems/top-k-frequent-words/

class Solution:
    def topKFrequent(self, words, k):
        """
        Inputs:
            words: list[str]
            k: int
        Outputs:
            res: list[str]
        """
        
        count = {}
        for i in words:
            count[i] = count.get(i,0) + 1
        
        words_sort = [kv[0] for kv in sorted(
                count.items(), key=lambda kv: (-kv[1],kv[0]))]
        return words_sort[0:k]