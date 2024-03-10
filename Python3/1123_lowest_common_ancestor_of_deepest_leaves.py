# https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.dfs(root)[0]

    def dfs(self, root):
        if root is None:
            return (root, 0)

        left = self.dfs(root.left)
        right = self.dfs(root.right)

        if left[1] > right[1]:
            return (left[0], left[1]+1)
        if left[1] < right[1]:
            return (right[0], right[1]+1)

        return (root, left[1]+1)