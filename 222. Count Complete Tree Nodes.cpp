class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftDepth = 0;
        for (TreeNode *cur = root; cur; cur = cur->left)
            ++leftDepth;
        int rightDepth = 0;
        for (TreeNode *cur = root; cur; cur = cur->right)
            ++rightDepth;
        return leftDepth == rightDepth ? (1 << leftDepth) - 1 : 1 + countNodes(root->left) + countNodes(root->right);
    }
};
