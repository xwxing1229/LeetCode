# https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sufficientSubset(self, root: Optional[TreeNode], limit: int) -> Optional[TreeNode]:
        root_delete = self.dfs(root, 0, limit)
        if root_delete:
            return None
        return root
    
    def dfs(self, node, s, limit):
        if node.left is None and node.right is None:
            return s + node.val < limit
        
        left_delete, right_delete = True, True

        if node.left:
            left_delete = self.dfs(node.left, s+node.val, limit)
        if node.right:
            right_delete = self.dfs(node.right, s+node.val, limit)
        
        if left_delete:
            node.left = None
        if right_delete:
            node.right = None
        
        return left_delete and right_delete