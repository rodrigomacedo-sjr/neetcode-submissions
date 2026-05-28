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

            n_max = max(node.val, m)
            good += dfs(node.left, n_max)
            good += dfs(node.right, n_max)
            return good

        return dfs(root, float("-inf"))
