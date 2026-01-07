# https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/

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
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        def dfs1(node: Optional[TreeNode]) -> int:
            if node is None:
                return 0
            return node.val + dfs1(node.left) + dfs1(node.right)
        
        def dfs2(node: Optional[TreeNode]) -> int:
            if node is None:
                return 0
            curr = node.val + dfs2(node.left) + dfs2(node.right)
            nonlocal res
            res = max(res, curr * (s - curr))
            return curr

        res = 0
        mod = int(1e9) + 7
        s = dfs1(root)
        dfs2(root)
        return res % mod

# class Solution:
#     def maxProduct(self, root: Optional[TreeNode]) -> int:
#         def dfs1(node: Optional[TreeNode]) -> int:
#             if node is None:
#                 return 0
#             return node.val + dfs1(node.left) + dfs1(node.right)

#         def dfs2(node: Optional[TreeNode]) -> int:
#             if node is None:
#                 return 0
#             s = node.val + dfs2(node.left) + dfs2(node.right)
#             nonlocal ans
#             ans = max(ans, s * (total - s))
#             return s

#         total = dfs1(root)

#         ans = 0
#         dfs2(root)

#         return ans % 1_000_000_007