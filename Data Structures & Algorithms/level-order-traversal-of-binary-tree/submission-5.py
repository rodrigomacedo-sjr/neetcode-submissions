# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: return []
        ans = []
        current_level = [root]

        while current_level:
            ans.append([n.val for n in current_level])

            current_level = [
                child
                for node in current_level
                for child in (node.left, node.right) if child
            ]

        return ans