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

        lh, lb = self.getHeight(root.left)
        rh, rb = self.getHeight(root.right)
        b = abs(lh - rh) <= 1

        return b and lb and rb

    
    def getHeight(self,root: Optional[TreeNode]):
        if not root:
            return (0, True)
        lHeight, lBalanced = self.getHeight(root.left)
        rHeight, rBalanced = self.getHeight(root.right)
        height = 1 + max(lHeight, rHeight)
        balanced = abs(lHeight - rHeight) <= 1

        return (height, balanced and lBalanced and rBalanced)