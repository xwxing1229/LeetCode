# https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        res = None
        depth_max = -1

        def dfs(node: Optional[TreeNode], depth: int) -> int:
            nonlocal res, depth_max
            if node is None:
                depth_max = max(depth_max, depth)
                return depth
            
            left_depth_max = dfs(node.left, depth+1)
            right_depth_max = dfs(node.right, depth+1)

            if left_depth_max == right_depth_max and left_depth_max == depth_max:
                res = node
            
            return max(left_depth_max, right_depth_max)

        dfs(root, 0)
        return res