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

        flag = abs(self.getHeight(root.left) - self.getHeight(root.right)) <= 1

        return flag and self.isBalanced(root.left) and self.isBalanced(root.right)

    
    def getHeight(self,root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return 1 + max(self.getHeight(root.left), self.getHeight(root.right))