# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        def pre(curr):
            if not curr:
                return
            res.append(curr.val)
            pre(curr.left)
            pre(curr.right)
        pre(root)
        return res
            