# https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

# # Definition of singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        Inputs:
            head: ListNode
            n: int
        Outputs:
            res: ListNode
        """

        dummy = ListNode(next=head)
        first = head
        second = dummy

        for _ in range(n):
            first = first.next

        while first:
            first = first.next
            second = second.next

        second.next = second.next.next
        res = dummy.next

        return res