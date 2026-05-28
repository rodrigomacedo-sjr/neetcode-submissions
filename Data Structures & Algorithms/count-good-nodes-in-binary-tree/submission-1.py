# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.good = 0

        def dfs(node, m):
            if node == None:
                return
            if node.val >= m:
                self.good += 1
            dfs(node.left, max(node.val, m))
            dfs(node.right, max(node.val, m))

        dfs(root, float("-inf"))
        return self.good
