# https://leetcode.cn/problems/validate-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.res = True
        self.check(root, -inf, inf)
        return self.res
    
    def check(self, node, min_, max_):
        if self.res == False:
            return False
        
        if node is None:
            return True
        x = node.val
        if x > min_ and x < max_:
            return self.check(node.left, min_, x) and self.check(node.right, x, max_)
        else:
            self.res = False
            return False