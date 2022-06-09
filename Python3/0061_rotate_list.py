# https://leetcode.cn/problems/rotate-list/

# Definition for singly-linked list.
# class ListNode:
# 	def __init__(self, val=0, next=None):
# 		self.val = val
# 		self.next = next

class Solution:
	def rotateRight(self, head, k):
		"""
		Inputs:
			head: Optional[ListNode]
			k: int
		Outputs:
			res: Optional[ListNode]
		"""

		if (k == 0) or (not head) or (not head.next):
			return head

		n = 1
		cur = head
		while cur.next:
			n = n + 1
			cur = cur.next

		# Connect head and tail.
		cur.next = head
		for i in range(n - k % n):
			cur = cur.next

		res = cur.next
		# Break.
		cur.next = None
		return res