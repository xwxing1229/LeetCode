# https://leetcode.cn/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> list[int]:
        extreme = []
        val_prev = head.val
        curr = head.next
        idx = 1
        while curr.next:
            val_curr = curr.val
            val_next = curr.next.val
            if val_curr > val_prev and val_curr > val_next:
                extreme.append(idx)
            elif val_curr < val_prev and val_curr < val_next:
                extreme.append(idx)
            val_prev = val_curr
            curr = curr.next
            idx += 1
        if len(extreme) < 2:
            return [-1, -1]
        res = [extreme[1] - extreme[0], extreme[-1] - extreme[0]]
        for i in range(1, len(extreme)):
            res[0] = min(res[0], extreme[i] - extreme[i-1])
        return res