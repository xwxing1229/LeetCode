# https://leetcode.cn/problems/binary-tree-coloring-game/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def btreeGameWinningMove(self, root: Optional[TreeNode], n: int, x: int) -> bool:
        x_node = None

        def getSubtreeSize(node):
            if node == None:
                return 0
            if node.val == x:
                nonlocal x_node
                x_node = node
            return 1 + getSubtreeSize(node.left) + getSubtreeSize(node.right)
        
        getSubtreeSize(root)
        left_size = getSubtreeSize(x_node.left)
        if left_size >= (n+1)//2:
            return True
        right_size = getSubtreeSize(x_node.right)
        if right_size >= (n+1)//2:
            return True
        return n - left_size - right_size - 1 >= (n+1)//2