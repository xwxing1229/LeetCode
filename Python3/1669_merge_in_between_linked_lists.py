# https://leetcode.cn/problems/merge-in-between-linked-lists/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        head, cur = list1, list1
        for i in range(b):
            if i == a - 1:
                start = cur
            cur = cur.next
        end = cur.next

        start.next = list2
        cur = list2
        while cur.next:
            cur = cur.next
        cur.next = end
        return head