# https://leetcode.cn/problems/maximum-twin-sum-of-a-linked-list/

from typing import Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        values = []
        while head:
            values.append(head.val)
            head = head.next
        res = values[0] + values[-1]
        n = len(values)
        for i in range(n // 2):
            res = max(res, values[i] + values[n-1-i])
        return res