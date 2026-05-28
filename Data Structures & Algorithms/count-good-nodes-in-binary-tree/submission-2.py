# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(node, m):
            good = 0
            if node is None:
                return 0
            if node.val >= m:
                good += 1
            good += dfs(node.left, max(node.val, m))
            good += dfs(node.right, max(node.val, m))
            return good

        return dfs(root, float("-inf"))
