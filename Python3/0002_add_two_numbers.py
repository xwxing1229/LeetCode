# https://leetcode.cn/problems/add-two-numbers/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res = l1
        carry = 0
        while l1 is not None and l2 is not None:
            s = l1.val + l2.val + carry
            l1.val = s % 10
            carry = s // 10

            cur = l1

            l1 = l1.next
            l2 = l2.next
        
        if l1 is None and l2 is None and carry:
            cur.next = ListNode(1)
        elif l1 is None and l2 is not None:
            cur.next = l2
            l1 = cur.next
        while l1 is not None:
            s = l1.val + carry
            l1.val = s % 10
            carry = s // 10

            cur = l1
            l1 = l1.next
        if carry:
            cur.next = ListNode(1)
            
        return res