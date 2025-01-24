# https://leetcode.cn/problems/merge-nodes-in-between-zeros/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        res = [ListNode()]
        stk = [head]
        cur = head.next
        while cur:
            if cur.val != 0:
                stk.append(cur)
            else:
                node = ListNode(0)
                while stk[-1].val != 0:
                    node.val += stk.pop().val
                res[-1].next = node
                res.append(node)
            cur = cur.next
        
        return res[0].next