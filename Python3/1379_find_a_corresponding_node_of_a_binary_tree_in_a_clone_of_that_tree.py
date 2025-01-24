# https://leetcode.cn/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        q1, q2 = deque(), deque()
        q1.append(original)
        q2.append(cloned)
        while q1:
            node1, node2 = q1.popleft(), q2.popleft()
            if node1 == target:
                return node2
            if node1.left:
                q1.append(node1.left)
                q2.append(node2.left)
            if node1.right:
                q1.append(node1.right)
                q2.append(node2.right)
        return None