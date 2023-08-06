# https://leetcode.cn/problems/swap-nodes-in-pairs/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        cur = ListNode()
        cur.next = head
        dummy.next = cur
        while head and head.next:
            tmp = head.next
            cur.next = tmp
            head.next = tmp.next
            tmp.next = head
            cur = head
            head = head.next
        return dummy.next.next