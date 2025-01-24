# https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        graph = defaultdict(list)
        def dfs(node):
            if node.left:
                graph[node.val].append(node.left.val)
                graph[node.left.val].append(node.val)
                dfs(node.left)
            if node.right:
                graph[node.val].append(node.right.val)
                graph[node.right.val].append(node.val)
                dfs(node.right)
        dfs(root)

        q = deque()
        q.append((start, 0))
        visited = set()
        visited.add(start)
        res = 0
        while q:
            cur_val, res = q.popleft()
            for val in graph[cur_val]:
                if val not in visited:
                    q.append((val, res+1))
                    visited.add(val)
        return res