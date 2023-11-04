# https://leetcode.cn/problems/validate-binary-search-tree/

"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return root

        q = deque()
        q.append(root)
        while len(q) > 0:
            n = len(q)
            last = None
            for i in range(n):
                cur = q.popleft()
                if cur.left:
                    q.append(cur.left)
                if cur.right:
                    q.append(cur.right)
                if i > 0:
                    last.next = cur
                last = cur
        return root