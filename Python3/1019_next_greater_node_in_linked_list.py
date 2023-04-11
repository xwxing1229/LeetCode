# https://leetcode.cn/problems/next-greater-node-in-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        nums = []
        while head != None:
            nums.append(head.val)
            head = head.next

        n = len(nums)
        res = [0 for _ in range(n)]
        st = []
        for i in range(n-1, -1, -1):
            while st and st[-1] <= nums[i]:
                st.pop()
            if st:
                res[i] = st[-1]
            st.append(nums[i])
        return res