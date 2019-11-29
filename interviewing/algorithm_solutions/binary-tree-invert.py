# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root != None:
            temp = self.invertTree(root.left)
            root.left = self.invertTree(root.right)
            root.right = temp
            return root
        return None

# Test
root = TreeNode(3)
root.left = TreeNode(2)
root.right = TreeNode(4)

Solution().invertTree(root)
print(root.val)
print(root.left.val)
print(root.right.val)