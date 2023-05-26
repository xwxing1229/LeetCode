# https://leetcode.cn/problems/shortest-path-in-binary-matrix/

class PriorityQueue:
    def __init__(self):
        self.elements = []

    def push(self, element, cost):
        heapq.heappush(self.elements, (cost, element))

    def pop(self):
        return heapq.heappop(self.elements)[1]

    def empty(self):
        return len(self.elements) == 0

class Solution:
    def shortestPathBinaryMatrix(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        self.n = len(grid[0])
        if grid[0][0] == 1 or grid[self.n-1][self.n-1] == 1:
            return -1

        dirs = [[-1,-1], [-1,0], [-1,1], [0,-1], [0,1], [1,-1], [1,0], [1,1]]
        start = (0, 0)
        cost_till_now = dict()
        cost_till_now[start] = 0
        pq = PriorityQueue()
        pq.push(start, 0)
        # come_from[n1] = n2 indicates the path n2 -> n1.
        come_from = dict()

        find = False
        while not pq.empty():
            cur = pq.pop()
            if cur[0] == self.n-1 and cur[1] == self.n-1:
                find = True
                break
            for d in dirs:
                neighbor = (cur[0] + d[0], cur[1] + d[1])
                if neighbor[0] < 0 or neighbor[0] >= self.n or\
                    neighbor[1] < 0 or neighbor[1] >= self.n:
                    continue
                if grid[neighbor[0]][neighbor[1]] == 1:
                    continue
                # +1 because moves in all directions have same costs.
                cost_to_neighbor = cost_till_now[cur] + 1
                if neighbor not in cost_till_now or\
                    cost_till_now[neighbor] > cost_to_neighbor:
                    cost_till_now[neighbor] = cost_to_neighbor
                    come_from[neighbor] = cur
                    pq.push(neighbor, cost_to_neighbor + self.heuristicCost(neighbor))

        if not find:
            return -1
        res = 1
        while cur[0] != 0 or cur[1] != 0:
            res += 1
            cur = come_from[cur]
        return res

    def heuristicCost(self, cur):
        # The heuristic cost should be designed to be consistent with the problem to
        # find a SHORTEST path.
        # In this problem, moves in all directions have same costs.
        return max(self.n-1-cur[0], self.n-1-cur[1])