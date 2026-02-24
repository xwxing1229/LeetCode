# https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/

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
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        res = 0

        def dfs(node: Optional[TreeNode], val: int):
            nonlocal res
            
            if node.left == None and node.right == None:
                res += val
                return
            
            if node.left:
                dfs(node.left, (val << 1) + node.left.val)
            if node.right:
                dfs(node.right, (val << 1) + node.right.val)
        
        dfs(root, root.val)

        return res