# https://leetcode.cn/problems/add-two-numbers-ii/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num1, num2 = "", ""
        while l1 is not None:
            num1 += str(l1.val)
            l1 = l1.next
        while l2 is not None:
            num2 += str(l2.val)
            l2 = l2.next
        if len(num1) < len(num2):
            num1, num2 = num2, num1

        n1, n2 = len(num1), len(num2)
        i, j = n1-1, n2-1
        carry = 0
        res = ""
        while j >= 0:
            s = int(num1[i]) + int(num2[j]) + carry
            res += str(s % 10)
            carry = s // 10
            i -= 1
            j -= 1
        while i >= 0:
            s = int(num1[i]) + carry
            res += str(s % 10)
            carry = s // 10
            i -= 1

        cur = ListNode(1)
        dummy = ListNode(0, cur)
        for i in range(n1-1, -1, -1):
            tmp = ListNode(int(res[i]))
            cur.next = tmp
            cur = cur.next
        if carry:
            return dummy.next
        else:
            return dummy.next.next