# https://leetcode.cn/problems/remove-nodes-from-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node = head
        st = []
        while node:
            while st and node.val > st[-1].val:
                st.pop()
            if not st:
                head = node
            else:
                st[-1].next = node
            st.append(node)
            node = node.next
        return head