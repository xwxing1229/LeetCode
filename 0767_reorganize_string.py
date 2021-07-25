# https://leetcode-cn.com/problems/reorganize-string/
class Solution:
    def reorganizeString(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """

        count = {}
        for i in s:
            count[i] = count.get(i,0) + 1

        heap = [(-v,k) for k,v in count.items()]
        heapq.heapify(heap)

        n = len(s)
        if -heap[0][0] > (n+1)//2:
            return ""

        res = []
        while len(heap) > 1:
            _, s1 = heapq.heappop(heap)
            _, s2 = heapq.heappop(heap)
            res.append(s1)
            res.append(s2)

            count[s1] = count[s1] - 1
            count[s2] = count[s2] - 1
            if count[s1] > 0:
                heapq.heappush((-count[s1], s1))
            if count[s2] > 0:
                heapq.heappush((-count[s2], s2))

        if len(heap) == 1:
            res.append(heap[0][1])

        return "".join(res)