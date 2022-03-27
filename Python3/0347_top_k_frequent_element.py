# https://leetcode-cn.com/problems/top-k-frequent-elements/

class Solution:
    def topKFrequent(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: list[int]
        """
        
        count = {}
        for i in nums:
            count[i] = count.get(i,0) + 1
        
        res = []
        count_sort = []
        for i in count:
            idx = bisect.bisect_left(count_sort, count[i])
            res.insert(idx, i)
            count_sort.insert(idx, count[i])
            
        res.reverse()
        return res[:k]