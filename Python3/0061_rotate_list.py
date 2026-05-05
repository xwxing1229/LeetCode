# https://leetcode.cn/problems/rotate-list/

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return head
        n = 1
        curr = head
        while curr.next:
            n += 1
            curr = curr.next
        k %= n

        curr.next = head

        last = head
        for _ in range(n-k-1):
            last = last.next
        res = last.next
        last.next = None
        return res