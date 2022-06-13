# https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        """
        Inputs:
            head: ListNode
        Outputs:
            res: ListNode
        """

        if head is None:
            return head

        tmp = ListNode()
        res = ListNode(0, tmp)
        cur = head
        cnt = 1
        while cur.next:
            if cur.val == cur.next.val:
                cnt = cnt + 1
            elif cnt < 2:
                tmp.next = cur
                tmp = tmp.next
                cnt = 1
            else:
                cnt = 1

            cur = cur.next

        if cnt < 2:
            tmp.next = cur
        else:
            tmp.next = None

        return res.next.next