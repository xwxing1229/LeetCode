# https://leetcode.cn/problems/delete-the-middle-node-of-a-linked-list/

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
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head.next:
            return None
        slow, fast = head, head
        pre = ListNode(next=slow)
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            pre = pre.next
        pre.next = slow.next
        return head