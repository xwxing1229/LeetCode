# https://leetcode.cn/problems/reverse-linked-list-ii/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head, left, right):
        """
        Inputs:
            head: ListNode
            left: int
            right: int
        Outputs:
            res: ListNode
        """

        dummy = ListNode(0, head)
        pre = dummy
        for _ in range(left - 1):
            pre = pre.next

        cur = pre.next
        for _ in range(right - left):
            tmp = cur.next
            cur.next = cur.next.next
            tmp.next = pre.next
            pre.next = tmp

        return dummy.next