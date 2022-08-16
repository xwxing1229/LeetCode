# https://leetcode.cn/problems/house-robber-iii/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root):
        """
        Inputs:
            root: optional[TreeNode]
        Outputs:
            res: int
        """
        self.dp_c = {} # this node is chosen
        self.dp_n = {} # this node is not chosen
        self.dfs(root)
        return max(self.dp_c[root], self.dp_n[root])

    def dfs(self, node):
        if node is None:
            return

        self.dfs(node.left)
        self.dfs(node.right)
        
        self.dp_c[node] = node.val + self.dp_n.get(node.left,0) + self.dp_n.get(node.right,0)
        self.dp_n[node] = max(self.dp_c.get(node.left,0), self.dp_n.get(node.left,0)) +\
            max(self.dp_c.get(node.right,0), self.dp_n.get(node.right,0))