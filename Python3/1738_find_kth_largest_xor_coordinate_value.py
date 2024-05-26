# https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value/

class Solution:
    def kthLargestValue(self, matrix, k):
        """
        Inputs:
            matrix: list[list[int]]
            k: int
        Outputs:
            res: int
        """
        m, n = len(matrix), len(matrix[0])
        values = [[matrix[0][0] for _ in range(n)] for _ in range(m)]
        pq = [-matrix[0][0]]
        for j in range(1, n):
            values[0][j] = (values[0][j-1] ^ matrix[0][j])
            heapq.heappush(pq, -values[0][j])
        for i in range(1, m):
            values[i][0] = (values[i-1][0] ^ matrix[i][0])
            row_xor = matrix[i][0]
            heapq.heappush(pq, -values[i][0])
            for j in range(1, n):
                row_xor = (row_xor ^ matrix[i][j])
                values[i][j] = (values[i-1][j] ^ row_xor)
                heapq.heappush(pq, -values[i][j])
        
        for _ in range(k-1):
            heapq.heappop(pq)
        return -heapq.heappop(pq)