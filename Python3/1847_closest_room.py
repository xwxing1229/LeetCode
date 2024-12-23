# https://leetcode.cn/problems/closest-room/

class Solution:
    def closestRoom(self, rooms, queries):
        """
        Inputs:
            rooms, queries: list[list[int]]
        Outputs:
            res: list[int]
        """
        res = [-1 for _ in range(len(queries))]

        rooms.sort(key=lambda x: (-x[1], x[0]))
        for i in range(len(queries)):
            queries[i].append(i)
        queries.sort(key=lambda x:-x[1])

        valid, valid_pre = 0, 0
        idxs = [rooms[0][0]] # valid indices
        for preferred, minsize, i in queries:
            if minsize > rooms[0][1]:
                continue
            left, right = valid_pre, len(rooms)-1
            while left <= right:
                mid = (left + right) // 2
                if rooms[mid][1] >= minsize:
                    left = mid + 1
                    valid = mid
                else:
                    right = mid - 1
            
            for k in range(valid_pre+1, valid+1):
                bisect.insort(idxs, rooms[k][0])
            valid_pre = valid

            if preferred <= idxs[0]:
                res[i] = idxs[0]
                continue
            elif preferred >= idxs[-1]:
                res[i] = idxs[-1]
                continue
            
            find = False
            idx_small, idx_big = -1, -1
            left, right = 0, valid
            while left <= right:
                mid = (left + right) // 2
                if idxs[mid] < preferred:
                    left = mid + 1
                    idx_small = idxs[mid]
                elif idxs[mid] > preferred:
                    right = mid - 1
                    idx_big = idxs[mid]
                else:
                    res[i] = idxs[mid]
                    find = True
                    break
            if find:
                continue
            if idx_big - preferred < preferred - idx_small:
                res[i] = idx_big
            else:
                res[i] = idx_small
        return res