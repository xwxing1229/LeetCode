# https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        cnts = [0 for _ in range(10)]

        def dfs(node):
            if node is None:
                return 0
            cnts[node.val] = 1 - cnts[node.val]
            if node.left is None and node.right is None:
                if sum(cnts) <= 1:
                    res = 1
                else:
                    res = 0
            else:
                res = dfs(node.left) + dfs(node.right)
            cnts[node.val] = 1 - cnts[node.val]
            return res
            
        return dfs(root)