# https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cumsum = 0
        seen = dict()
        dummy = ListNode(0, head)
        seen[0] = dummy
        while head:
            cumsum += head.val
            seen[cumsum] = head
            head = head.next
        head = dummy
        cumsum = 0
        while head:
            cumsum += head.val
            head.next = seen[cumsum].next
            head = head.next
        return dummy.next
