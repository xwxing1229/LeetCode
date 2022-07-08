# https://leetcode.cn/problems/reverse-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        """
        Inputs:
            head: ListNode
        Outputs:
            res: ListNode
        """
        res = None
        pre = head
        while pre:
            tmp = pre.next
            pre.next = res
            res = pre
            pre = tmp
        return res
