# https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        res, depth = 1, 1
        s_max = root.val
        q = deque()
        q.append(root)
        while q:
            n = len(q)
            s_curr = 0
            for _ in range(n):
                node = q.popleft()
                s_curr += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if s_curr > s_max:
                res = depth
                s_max = s_curr
            depth += 1
        return res