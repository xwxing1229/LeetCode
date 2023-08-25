# https://leetcode.cn/problems/count-good-nodes-in-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0
        return self.check(root, root.val)

    def check(self, node, cur_max):
        if node is None:
            return 0
        val = node.val
        if val >= cur_max:
            return 1 + self.check(node.left, val) + self.check(node.right, val)
        else:
            return self.check(node.left, cur_max) + self.check(node.right, cur_max)