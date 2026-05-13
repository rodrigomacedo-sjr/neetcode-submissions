# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        return self.getHeight(root)[1]

    def getHeight(self,root: Optional[TreeNode]) -> tuple[int, bool]:
        if not root:
            return (0, True)
        lHeight, lBalanced = self.getHeight(root.left)
        rHeight, rBalanced = self.getHeight(root.right)
        height = 1 + max(lHeight, rHeight)
        balanced = abs(lHeight - rHeight) <= 1

        return (height, balanced and lBalanced and rBalanced)