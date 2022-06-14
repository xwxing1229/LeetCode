# https://leetcode.cn/problems/partition-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def partition(self, head, x):
        """
        Inputs:
            head: ListNode
            x: int
        Outputs:
            res: ListNode
        """

        small = ListNode()
        small_head = small
        large = ListNode()
        large_head = large
        while head:
            if head.val < x:
                small.next = head
                small = small.next
            else:
                large.next = head
                large = large.next

            head = head.next

        small.next = large_head.next
        large.next = None
        
        return small_head.next