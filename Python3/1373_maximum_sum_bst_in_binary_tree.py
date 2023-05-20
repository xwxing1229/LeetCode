# https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        res = 0

        def dfs(node):
            if node is None:
                return inf, -inf, 0
            
            left_min, left_max, left_sum = dfs(node.left)
            right_min, right_max, right_sum = dfs(node.right)
            x = node.val
            if x <= left_max or x >= right_min:
                return -inf, inf, 0
            
            s = left_sum + right_sum + x
            nonlocal res
            res = max(res, s)

            return min(left_min, x), max(right_max, x), s
        
        dfs(root)
        return res
