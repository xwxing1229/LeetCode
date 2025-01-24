# https://leetcode.cn/problems/find-elements-in-a-contaminated-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.vals = {0}
        root.val = 0
        self.recover(root)

    def find(self, target: int) -> bool:
        if target in self.vals:
            return True
        else:
            return False

    def recover(self, node):
        x = node.val
        if node.left:
            val = 2 * x + 1
            node.left.val = val
            self.vals.add(val)
            self.recover(node.left)
        if node.right:
            val = 2 * x + 2
            node.right.val = val
            self.vals.add(val)
            self.recover(node.right)


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)