# https://leetcode.cn/problems/delete-nodes-and-return-forest/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        self.s = set(to_delete)
        self.res = []
        self.dfs(root, True)
        return self.res

    def dfs(self, node: Optional[TreeNode], is_root: bool) ->  Optional[TreeNode]:
        if node == None:
            return None
        delete = node.val in self.s
        node.left = self.dfs(node.left, delete)
        node.right = self.dfs(node.right, delete)
        if delete:
            return None
        else:
            if is_root:
                self.res.append(node)
            return node