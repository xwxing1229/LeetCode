# https://leetcode.cn/problems/linked-list-components/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def numComponents(self, head, nums):
        """
        Inputs:
            head: Optional[ListNode]
            nums: list[int]
        Outputs:
            res: int
        """

        s = set(nums)
        res = 0
        pre_in_list = False
        while head is not None:
            if head.val in s:
                if not pre_in_list:
                    res = res + 1
                    pre_in_list = True
            else:
                pre_in_list = False
            head = head.next
        return res