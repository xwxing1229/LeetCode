# https://leetcode.cn/problems/merge-k-sorted-lists/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # res = None
        # for ln in lists:
        #     res = self.mergeTwoLists(res, ln)
        # return res
        return self.merge(lists, 0, len(lists)-1)

    def merge(self, lists, left, right):
        if left == right:
            return lists[left]
        elif left > right:
            return None
        mid = (left + right) // 2
        return self.mergeTwoLists(self.merge(lists,left,mid), self.merge(lists,mid+1,right))

    def mergeTwoLists(self, l1, l2):
        head, cur = ListNode(), ListNode()
        head.next = cur
        while l1 is not None and l2 is not None:
            if l1.val < l2.val:
                cur.next = l1
                cur = cur.next
                l1 = l1.next
            else:
                cur.next = l2
                cur = cur.next
                l2 = l2.next
        if l1 is not None:
            cur.next = l1
        if l2 is not None:
            cur.next = l2
        return head.next.next