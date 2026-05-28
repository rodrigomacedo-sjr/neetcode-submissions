# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        good = []

        def dfs(node, m):
            if node == None:
                return
            if node.val >= m:
                good.append(1)
            dfs(node.left, max(node.val, m))
            dfs(node.right, max(node.val, m))

        dfs(root, float("-inf"))
        return len(good)
